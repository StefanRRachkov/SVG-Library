//
// Created by User on 4.6.2019 г..
//

#ifndef SVG_LINE_H
#define SVG_LINE_H

#include "SVG_Figure.h"

class Line : public Figure
{
    private:
        std::pair<double, double> endPoint;
    public:
        Line(double, double, double, double);
        Line& operator=(const Line&);

        std::string ToString() override;
        std::string SVG_StringFormat() override;
};

#endif //SVG_LINE_H
