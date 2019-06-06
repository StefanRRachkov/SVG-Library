//
// Created by User on 3.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Erase.h"
#include <iostream>

void Erase::Execute(const std::string& elementIndex)
{
    auto index = new unsigned int;
    *index = std::stoi(elementIndex);
    if(*index > this -> figureContainer -> GetFigures().size())
    {
        this -> message = "There is no figure number " + std::to_string(*index) + "!\n";
    }
    else
    {
        this -> figureContainer -> DeleteFigures(*index - 1);
        this -> message = "Erased figure (" + std::to_string(*index) + ")\n";
    }
}


Erase::Erase(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}