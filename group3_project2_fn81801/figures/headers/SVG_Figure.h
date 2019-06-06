//
// Created by User on 14.05.2019 г..
//

#ifndef SVG_SVG_FIGURE_H
#define SVG_SVG_FIGURE_H

#include <utility>
#include <vector>
#include <string>

class Figure
{
    protected:
        std::pair<double, double> coordinate;
        std::vector<double> boundaries;
        std::vector<std::pair<double, double>> circleArea;
    public:
        Figure();

        virtual Figure& operator=(const Figure&);

        virtual std::string ToString();
        virtual std::string SVG_StringFormat();

        void Translate(int, int);
        std::pair<double, double> GetCoordinates();
        std::vector<double> GetBoundaries();
        std::vector<std::pair<double, double>> GetCircleArea();
};

#endif //SVG_SVG_FIGURE_H