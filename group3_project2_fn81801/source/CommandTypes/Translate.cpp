//
// Created by User on 3.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Translate.h"
#include <iostream>

void Translate::Execute(const std::string& movement)
{
    auto* vertical = new int;
    auto* horizontal = new int;
    auto* index = new int;
    try
    {
        *index = std::stoi(movement);
    }
    catch(const std::invalid_argument& ia)
    {
        *index = -1;
    }

    *vertical = 0;
    *horizontal = 0;

    auto* contentMatch = new std::smatch;
    if(std::regex_search(movement, *contentMatch, std::regex("(vertical)+\\s*(=)+")))
    {
        *vertical = std::stoi(contentMatch -> suffix().str());
    }
    if(std::regex_search(movement, *contentMatch, std::regex("(horizontal)+\\s*(=)+")))
    {
        *horizontal = std::stoi(contentMatch -> suffix().str());
    }

    if(*index > 0 && *index <= this -> figureContainer -> GetFigures().size())
    {
        this -> figureContainer -> GetFigures().at(*index - 1) -> Translate(*horizontal, *vertical);
        this -> message = "Translated figure (" + std::to_string(*index) + ")\n";
    }
    else
    {
        for(auto figure : this -> figureContainer -> GetFigures())
        {
            figure -> Translate(*horizontal, *vertical);
        }
        this -> message = "Translated all figures\n";
    }
}
Translate::Translate(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}