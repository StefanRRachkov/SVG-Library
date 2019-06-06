//
// Created by User on 14.05.2019 г..
//

#include "../headers/Rect.h"

Rect::Rect(double x, double y, double w, double h)
{
    this -> coordinate.first = x;
    this -> coordinate.second = y;
    this -> width = w;
    this -> height = h;

    this -> boundaries.push_back(x);
    this -> boundaries.push_back(y);
    this -> boundaries.push_back(x + w);
    this -> boundaries.push_back(y + h);

    this -> circleArea.emplace_back(x, y);
    this -> circleArea.emplace_back(x, y + w);
    this -> circleArea.emplace_back(x + h, y);
    this -> circleArea.emplace_back(x + h, y + w);
}

std::string Rect::ToString()
{
    std::string attributesToString;

    std::vector<double> values{
            this -> coordinate.first,
            this -> coordinate.second,
            this -> width,
            this -> height
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

    return "rectangle " + attributesToString;
}

std::string Rect::SVG_StringFormat()
{
    std::string svgFormat = "<rect ";

    auto* format = new std::string;
    *format = std::to_string(this -> coordinate.first);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("x=\"" + *format + "\" ");

    *format = std::to_string(this -> coordinate.second);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("y=\"" + *format + "\" ");

    *format = std::to_string(this -> width);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("width=\"" + *format + "\" ");

    *format = std::to_string(this -> height);
    format -> erase(format -> find('.') + 3, std::string::npos);

    svgFormat += ("height=\"" + *format + "\" />");

    delete(format);

    return svgFormat  + '\n';
}

Rect &Rect::operator=(const Rect& rRect)
{
    this -> coordinate.first = rRect.coordinate.first;
    this -> coordinate.second = rRect.coordinate.second;
    this -> width = rRect.width;
    this -> height = rRect.height;

    return *this;
}
