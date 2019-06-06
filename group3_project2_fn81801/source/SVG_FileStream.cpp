//
// Created by User on 3.6.2019 г..
//

#include "../headers/SVG_FileStream.h"
#include <regex>
#include <iostream>

const std::regex extract_SVG("(<\\s*svg[^>]+>)[^]*?(<[/]svg>)");
const std::regex extract_Comment("(<!--)[^]*?(-->)");

enum regex{RECT, CIRCLE, ELLIPSE, LINE, POLYLINE, POLYGON};
const std::regex extractor[] =
        {
                std::regex("<\\s*rect[^/]*[/]>"),
                std::regex("<\\s*circle[^/]*[/]>"),
                std::regex("<\\s*ellipse[^/]*[/]>"),
                std::regex("<\\s*line[^/]*[/]>"),
                std::regex("<\\s*polyline[^/]*[/]>"),
                std::regex("<\\s*polygon[^/]*[/]>")
        };

FileStream::FileStream() = default;

FileStream::FileStream(const std::string& filePath)
{
    this -> fileName = filePath;
    this -> svgFile.open(this -> fileName);
}

bool FileStream::Open(const std::string& filePath)
{
    if(this -> svgFile.is_open())
    {
        return true;
    }
    else
    {
        this -> fileName = filePath;
        this -> svgFile.open(this -> fileName);
        return this -> svgFile.is_open();
    }
}

void FileStream::Save(const std::vector<std::string>& content)
{
    this -> svgFile.close();
    this -> svgFile.open(this -> fileName);
    if (this -> svgFile.is_open())
    {
        std::string* fileStream;
        fileStream = new std::string;

        std::string* fileToString;
        fileToString = new std::string;
        *fileToString = "";
        while(getline(this -> svgFile, *fileStream))
        {
            *fileToString += (*fileStream + '\n');
        }
        std::smatch* matchedContent;
        matchedContent = new std::smatch;
        if(std::regex_search(*fileToString, *matchedContent, std::regex("(<[?]xml)[^]*?(<[/]svg>)")))
        {
            *fileToString = matchedContent -> str(0);

            auto* addFlag = new bool;
            *addFlag = false;

            for(const auto &figureSVG : extractor)
            {
                while(std::regex_search(*fileToString, *matchedContent, figureSVG))
                {
                    if(*addFlag)
                    {
                        *fileToString = matchedContent -> prefix().str() + matchedContent -> suffix().str();
                    }
                    else
                    {
                        *fileToString = matchedContent -> prefix().str() + "<!-- ADD -->" + matchedContent -> suffix().str();
                        *addFlag = true;
                    }
                }
            }
            delete(addFlag);
        }

        // Overwrite Content

        auto* newContent = new std::string;
        for(const auto& figure : content)
        {
            *newContent += figure;
        }
        *fileToString = std::regex_replace(*fileToString, extract_Comment, *newContent);
        auto overwrite = new std::ofstream;
        overwrite -> open(this -> fileName, std::ios::trunc);
        *overwrite << *fileToString;

        delete(newContent);
        delete(matchedContent);
        delete(fileStream);
        delete(fileToString);
        delete(overwrite);
    }
}

std::vector<std::string> FileStream::Read()
{
    std::vector<std::string> content;

    if (this -> svgFile.is_open())
    {
        std::string* fileStream;
        fileStream = new std::string;

        std::string* fileToString;
        fileToString = new std::string;
        *fileToString = "";

        while(getline(this -> svgFile, *fileStream))
        {
            *fileToString += (*fileStream + '\n');
        }
        /// Check if there is a <svg> tag
        std::smatch* matchedContent;
        matchedContent = new std::smatch;
        if(std::regex_search(*fileToString, *matchedContent, extract_SVG))
        {
            /// Extracting only the SVG content and deleting all the comments
            *fileToString = matchedContent -> str(0);
            *fileToString = std::regex_replace(*fileToString, extract_Comment, "");

            /// Extracting all figures
            for(const auto &figureSVG : extractor)
            {
                while(std::regex_search(*fileToString, *matchedContent, figureSVG))
                {
                    /// Extract Figures via Regex <std::smatch>
                    content.push_back(matchedContent -> str(0));
                    *fileToString = matchedContent -> prefix().str() + matchedContent -> suffix().str();
                }
            }
        }
        delete(matchedContent);
        delete(fileStream);
        delete(fileToString);
    }
    return content;
}

std::string FileStream::GetFilePath()
{
    return this -> fileName;
}

FileStream::~FileStream()
{
    this -> svgFile.close();
}
