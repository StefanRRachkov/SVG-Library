//
// Created by User on 4.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Save.h"

bool Save::Execute()
{
    this -> file -> Save(this -> figureContainer -> GetFormatSVG());
    this -> message = "Successfully saved the changes to " + this -> file -> GetFilePath() + '\n';
    return false;
}

Save::Save(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}