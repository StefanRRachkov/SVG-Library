//
// Created by User on 3.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Within.h"
#include <iostream>

void Within::Execute(const std::string& rawArea)
{
    auto* area = new std::string;
    *area = rawArea;

    this -> message = "";
    if(area -> find("rectangle") != std::string::npos)
    {
        area -> erase(area -> begin(), area -> begin() + area -> find("rectangle"));
        area -> erase(0, 9);

        auto* counter = new int;
        *counter = 0;
        auto* values = new std::vector<double>();
        ExtractSequenceOfNumbers(*area, values);

        for(auto figure : this -> figureContainer -> GetFigures())
        {
            if(values -> at(0) <= figure -> GetBoundaries().at(0) && values -> at(1) <= figure -> GetBoundaries().at(1))
            {
                if(values -> at(2) + values -> at(0) >= figure -> GetBoundaries().at(2) && values -> at(3) + values -> at(1) >= figure -> GetBoundaries().at(3))
                {
                    *counter += 1;
                    this -> message += std::to_string(*counter) + ". " + figure -> ToString() + '\n';
                }
            }
        }

        if(*counter == 0)
        {
            //TODO: Format
            this -> message = "No figures are located within rectangle "    + std::to_string(values -> at(0)) + ' '
                              + std::to_string(values -> at(1)) + ' '
                              + std::to_string(values -> at(2)) + ' '
                              + std::to_string(values -> at(3)) + '\n';
        }

        delete(counter);
        delete(values);
    }
    else if(area -> find("circle") != std::string::npos)
    {
        area -> erase(area -> begin(), area -> begin() + area -> find("circle"));
        area -> erase(0, 6);

        auto* counter = new int;
        *counter = 0;
        auto* values = new std::vector<double>();
        ExtractSequenceOfNumbers(*area, values); /// Xc Yc R

        auto* distance = new double;
        auto* check = new bool;

        for(auto figureCheck : this -> figureContainer -> GetFigures())
        {
            *check = true;
            for(auto point : figureCheck -> GetCircleArea())
            {
                *distance = sqrt(pow(point.first - values -> at(0), 2) + pow(point.second - values -> at(1), 2));
                if(*distance >= values -> at(2))
                {
                    *check = false;
                    break;
                }
            }
            if(*check)
            {
                *counter += 1;
                this -> message += std::to_string(*counter) + ". " + figureCheck -> ToString() + '\n';
            }
        }
        if(*counter == 0)
        {
            //TODO: Format
            this -> message = "No figures are located within circle  "    + std::to_string(values -> at(0)) + ' '
                              + std::to_string(values -> at(1)) + ' '
                              + std::to_string(values -> at(2)) +'\n';
        }
        delete(counter);
        delete(values);
        delete(distance);
        delete(check);
    }
}

Within::Within(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}