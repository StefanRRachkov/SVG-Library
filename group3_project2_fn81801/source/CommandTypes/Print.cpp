//
// Created by User on 3.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Print.h"
#include <iostream>

bool Print::Execute()
{
    auto figureContent = new std::string;
    for(unsigned int index = 0; index < this -> figureContainer -> GetFigures().size(); index++)
    {
        *figureContent += std::string{
                std::to_string(index + 1) +
                ". " +
                this -> figureContainer -> GetFigures().at(index) -> ToString() +
                '\n'
        };
    }

    this -> message = *figureContent;
    delete(figureContent);

    return false;
}

Print::Print(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}