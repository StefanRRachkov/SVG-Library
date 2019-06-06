//
// Created by User on 3.6.2019 г..
//

#include "../headers/SVG_FigureStorage.h"
#include <regex>
#include <iostream>

const std::regex extract_Digit("\"[\\d.]+");
const std::regex extract_TheDigit("[\\d.]+");
enum regex{RECT, CIRCLE, LINE, ELLIPSE, POLYLINE, POLYGON};
const std::regex extractor[] =
        {
                std::regex("<\\s*rect[^/]*[/]>"),
                std::regex("<\\s*circle[^/]*[/]>"),
                std::regex("<\\s*line[^/]*[/]>"),
                std::regex("<\\s*ellipse[^/]*[/]>"),
                std::regex("<\\s*polyline[^/]*[/]>"),
                std::regex("<\\s*polygon[^/]*[/]>")
        };
const std::regex rectAttributes[] =
        {
                std::regex("( x\\s*=\")(.*?)\""),
                std::regex("( y\\s*=\")(.*?)\""),
                std::regex("( width\\s*=\")(.*?)\""),
                std::regex("( height\\s*=\")(.*?)\"")
        };
const std::regex circleAttributes[] =
        {
                std::regex("( cx\\s*=\")(.*?)\""),
                std::regex("( cy\\s*=\")(.*?)\""),
                std::regex("( r\\s*=\")(.*?)\"")
        };
const std::regex lineAttributes[] =
        {
                std::regex("( x1\\s*=\")(.*?)\""),
                std::regex("( y1\\s*=\")(.*?)\""),
                std::regex("( x2\\s*=\")(.*?)\""),
                std::regex("( y2\\s*=\")(.*?)\"")
        };

std::vector<Figure*> ParseFromString(const std::vector<std::string>& svgStream)
{
    std::vector<Figure*> svgFigure;

    for (const auto &svg : svgStream)
    {
        std::vector<double>* attribute;
        attribute = new std::vector<double>;

        std::string* matchStorage;
        matchStorage = new std::string;

        std::smatch* matchedContent;
        matchedContent = new std::smatch;
        if(std::regex_search(svg, *matchedContent, extractor[RECT]))
        {
            for(const auto &variable : rectAttributes)
            {
                if(std::regex_search(svg, *matchedContent, variable))
                {
                    *matchStorage = matchedContent -> str(0);
                    if(std::regex_search(*matchStorage, *matchedContent, extract_Digit))
                    {
                        *matchStorage = matchedContent -> str(0);
                        if(std::regex_search(*matchStorage, *matchedContent, extract_TheDigit))
                        {
                            attribute -> emplace_back(stod(matchedContent -> str(0)));
                        }
                    }
                }
                else
                {
                    attribute -> push_back(0.0f);
                }
            }
            svgFigure.emplace_back(new Rect(attribute -> at(0), attribute -> at(1), attribute -> at(2), attribute -> at(3)));
        }
        else if(std::regex_search(svg, *matchedContent, extractor[CIRCLE]))
        {
            for(const auto &variable : circleAttributes)
            {
                if(std::regex_search(svg, *matchedContent, variable))
                {
                    *matchStorage = matchedContent -> str(0);
                    if(std::regex_search(*matchStorage, *matchedContent, extract_Digit))
                    {
                        *matchStorage = matchedContent -> str(0);
                        if(std::regex_search(*matchStorage, *matchedContent, extract_TheDigit))
                        {
                            attribute -> emplace_back(stod(matchedContent -> str(0)));
                        }
                    }
                }
                else
                {
                    attribute -> push_back(0.0f);
                }
            }
            svgFigure.emplace_back(new Circle(attribute -> at(0), attribute -> at(1), attribute -> at(2)));
        }
        else if(std::regex_search(svg, *matchedContent, extractor[LINE]))
        {
            for(const auto &variable : lineAttributes)
            {
                if(std::regex_search(svg, *matchedContent, variable))
                {
                    *matchStorage = matchedContent -> str(0);
                    if(std::regex_search(*matchStorage, *matchedContent, extract_Digit))
                    {
                        *matchStorage = matchedContent -> str(0);
                        if(std::regex_search(*matchStorage, *matchedContent, extract_TheDigit))
                        {
                            attribute -> emplace_back(stod(matchedContent -> str(0)));
                        }
                    }
                }
                else
                {
                    attribute -> push_back(0.0f);
                }
            }
            svgFigure.emplace_back(new Line(attribute -> at(0), attribute -> at(1), attribute -> at(2), attribute -> at(3)));
        }
        delete(attribute);
        delete(matchStorage);
        delete(matchedContent);
    }
    return svgFigure;
}

FigureStorage::FigureStorage() = default;


FigureStorage::FigureStorage(const std::vector<Figure*>& contentFigure)
{
    this -> svgFigure = contentFigure;
}

void FigureStorage::LoadFigures(const std::vector<Figure*>& contentFigure)
{
    this -> svgFigure = contentFigure;
}

std::vector<Figure *> FigureStorage::GetFigures()
{
    return this -> svgFigure;
}

std::vector<std::string> FigureStorage::GetFormatSVG()
{
    std::vector<std::string> contentSVG;
    for(auto figure : this -> svgFigure)
    {
        contentSVG.push_back(figure->SVG_StringFormat());
    }
    return contentSVG;
}

FigureStorage::~FigureStorage()
{
    for(auto figure : this -> svgFigure)
    {
        delete(figure);
    }
}

void FigureStorage::DeleteFigures(unsigned int index)
{
    this -> svgFigure.erase(this -> svgFigure.begin() + index);
}
