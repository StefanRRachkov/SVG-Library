//
// Created by User on 4.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Exit.h"

bool Exit::Execute()
{
    delete(this -> file);
    delete(this -> svgContent);
    delete(this -> figureContainer);

    this -> message = "Exit\n";

    return true;
}

Exit::Exit(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}