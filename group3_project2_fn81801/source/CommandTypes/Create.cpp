//
// Created by User on 3.6.2019 г..
//

#include "../../headers/SVG_CommandTypes/Create.h"
#include <iostream>

void Create::Execute(const std::string& rawDescription)
{
    auto* description = new std::string;
    *description = rawDescription;

    auto container = new std::vector<Figure*>;
    *container = this -> figureContainer -> GetFigures();

    if(description -> find("rectangle") != std::string::npos)
    {
        description -> erase(description -> begin(), description -> begin() + description -> find("rectangle"));
        description -> erase(0, 9);
        auto* values = new std::vector<double>();
        ExtractSequenceOfNumbers(*description, values);

        container -> emplace_back(new Rect(values -> at(0), values -> at(1), values -> at(2), values -> at(3)));

        delete(values);

        this -> message = "Successfully created rectangle\n";
    }
    else if(description -> find("circle") != std::string::npos)
    {
        description -> erase(description -> begin(), description -> begin() + description -> find("circle"));
        description -> erase(0, 6);
        auto* values = new std::vector<double>();
        ExtractSequenceOfNumbers(*description, values);

        container -> emplace_back(new Circle(values -> at(0), values -> at(1), values -> at(2)));

        delete(values);

        this -> message = "Successfully created circle\n";
    }
    else if(description -> find("line") != std::string::npos)
    {
        description -> erase(description -> begin(), description -> begin() + description -> find("line"));
        description -> erase(0, 4);
        auto* values = new std::vector<double>();
        ExtractSequenceOfNumbers(*description, values);

        container -> emplace_back(new Line(values -> at(0), values -> at(1), values -> at(2), values -> at(3)));

        delete(values);

        this -> message = "Successfully created circle\n";
    }
    else if(false)
    {
        // TODO: Other Figures
    }

    this -> figureContainer -> LoadFigures(*container);
    delete(container);
}

Create::Create(FileStream* file, ContentStorage* content, FigureStorage* figures) : CommandType(file, content, figures)
{

}
