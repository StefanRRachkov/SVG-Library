//
// Created by User on 4.6.2019 г..
//
#include "../headers/Circle.h"

Circle::Circle(double cx, double cy, double r)
{
    this -> coordinate.first = cx;
    this -> coordinate.second = cy;
    this -> radius = r;

    this -> boundaries.push_back(cx - r);
    this -> boundaries.push_back(cy - r);
    this -> boundaries.push_back(cx + r);
    this -> boundaries.push_back(cy + r);

    this -> circleArea.emplace_back(cx, cy - r);
    this -> circleArea.emplace_back(cx - r, cy);
    this -> circleArea.emplace_back(cx, cy + r);
    this -> circleArea.emplace_back(cx - r, cy);
}

std::string Circle::ToString()
{
    std::string attributesToString;

    std::vector<double> values{
            this -> coordinate.first,
            this -> coordinate.second,
            this -> radius
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

    return "circle " + attributesToString;
}

std::string Circle::SVG_StringFormat()
{
    std::string svgFormat = "<circle ";

    auto* format = new std::string;
    *format = std::to_string(this -> coordinate.first);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("cx=\"" + *format + "\" ");

    *format = std::to_string(this -> coordinate.second);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("cy=\"" + *format + "\" ");

    *format = std::to_string(this -> radius);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("r=\"" + *format + "\" />");

    delete(format);

    return svgFormat  + '\n';
}

Circle &Circle::operator=(const Circle& rCircle)
{
    this -> coordinate.first = rCircle.coordinate.first;
    this -> coordinate.second = rCircle.coordinate.second;
    this -> radius = rCircle.radius;

    return *this;
}