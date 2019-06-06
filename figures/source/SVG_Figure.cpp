//
// Created by User on 14.05.2019 г..
//
#include "../headers/SVG_Figure.h"

Figure::Figure() = default;

std::string Figure::ToString()
{
    return std::string();
}

std::string Figure::SVG_StringFormat()
{
    return std::string();
}


std::pair<double, double> Figure::GetCoordinates()
{
    return this -> coordinate;
}

void Figure::Translate(int horizontal, int vertical)
{
    this -> coordinate.first += horizontal;
    this -> coordinate.second += vertical;
}

std::vector<double> Figure::GetBoundaries()
{
    return this -> boundaries;
}

std::vector<std::pair<double, double>> Figure::GetCircleArea()
{
    return this -> circleArea;
}

Figure &Figure::operator=(const Figure& rFigure)
{
    this -> coordinate.first = rFigure.coordinate.first;
    this -> coordinate.second = rFigure.coordinate.second;
    this -> boundaries = rFigure.boundaries;
    this -> circleArea = rFigure.circleArea;

    return *this;
}
