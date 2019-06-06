//
// Created by User on 3.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/CommandType.h"
#include <regex>


void ExtractSequenceOfNumbers(std::string description, std::vector<double>* valueContainer)
{
    auto* matchedContent = new std::smatch;
    while(std::regex_search(description, *matchedContent, std::regex("[-]?[\\d.]+")))
    {
        valueContainer -> push_back(std::stod(matchedContent -> str()));
        description = matchedContent -> prefix().str() + matchedContent -> suffix().str();
    }
    delete(matchedContent);
}

CommandType::CommandType() = default;

CommandType::CommandType(FileStream* file, ContentStorage* container, FigureStorage* figures)
{
    this -> file = file;
    this -> svgContent = container;
    this -> figureContainer = figures;
}

CommandType::CommandType(const CommandType& rCommand)
{
    this -> file = rCommand.file;
    this -> svgContent = rCommand.svgContent;
    this -> figureContainer = rCommand.figureContainer;
}


void CommandType::Execute(const std::string&)
{

}

bool CommandType::Execute()
{
    return false;
}

std::string CommandType::GetMessage()
{
    return this -> message;
}

FileStream* CommandType::GetFile()
{
    return this -> file;
}

ContentStorage* CommandType::GetContent()
{
    return this -> svgContent;
}

FigureStorage* CommandType::GetFigures()
{
    return this -> figureContainer;
}

CommandType::~CommandType()
{
    delete(this -> file);
    delete(this -> svgContent);
    delete(this -> figureContainer);
}

