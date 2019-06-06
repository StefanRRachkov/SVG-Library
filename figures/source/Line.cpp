//
// Created by User on 4.6.2019 г..
//

#include "../headers/Line.h"

Line::Line(double x1, double y1, double x2, double y2)
{
    this -> coordinate.first = x1;
    this -> coordinate.second = y1;
    this -> endPoint.first = x2;
    this -> endPoint.second = y2;

    this -> boundaries.push_back(x1);
    this -> boundaries.push_back(y1);
    this -> boundaries.push_back(x2);
    this -> boundaries.push_back(y2);

    this -> circleArea.emplace_back(x1, y1);
    this -> circleArea.emplace_back(x2, y2);
}

std::string Line::ToString()
{
    std::string attributesToString;

    std::vector<double> values{
            this -> coordinate.first,
            this -> coordinate.second,
            this -> endPoint.first,
            this -> endPoint.second
    };

    auto* value = new std::string;
    for(auto attribute : values)
    {
        *value = std::to_string(attribute);
        value -> erase(value -> find('.') + 3, std::string::npos);
        attributesToString += (*value + ' ');
    }

    delete(value);
    values.clear();

    return "line " + attributesToString;
}

std::string Line::SVG_StringFormat()
{
    std::string svgFormat = "<line ";

    auto* format = new std::string;
    *format = std::to_string(this -> coordinate.first);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("x1=\"" + *format + "\" ");

    *format = std::to_string(this -> coordinate.second);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("y1=\"" + *format + "\" ");

    *format = std::to_string(this -> endPoint.first);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("x2=\"" + *format + "\" ");

    *format = std::to_string(this -> endPoint.second);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("y2=\"" + *format + R"(" stroke="green" stroke-width="5"/>)");

    delete(format);

    return svgFormat  + '\n';
}

Line &Line::operator=(const Line& rRect)
{
    this -> coordinate.first = rRect.coordinate.first;
    this -> coordinate.second = rRect.coordinate.second;
    this -> endPoint.first = rRect.endPoint.first;
    this -> endPoint.second = rRect.endPoint.second;

    return *this;
}
