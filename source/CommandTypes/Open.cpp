//
// Created by User on 3.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Open.h"
#include <iostream>

void Open::Execute(const std::string& filePath)
{
    if(this -> file -> Open(filePath))
    {
        this -> svgContent -> SetContent(this -> file -> Read(), ON_OPEN);
        this -> figureContainer -> LoadFigures(ParseFromString(this -> svgContent -> GetContent()));
        this -> message = "File is Opened\n";
    }
    else
    {
        this -> message = "Failed to Connect!\n";
    }
}

Open::Open(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}
