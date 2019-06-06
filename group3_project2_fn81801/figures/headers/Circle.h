//
// Created by User on 4.6.2019 г..
//

#ifndef SVG_CIRCLE_H
#define SVG_CIRCLE_H

#include "SVG_Figure.h"

class Circle : public Figure
{
    private:
        double radius;
    public:
        Circle(double, double, double);
        Circle& operator=(const Circle&);

        std::string ToString() override;
        std::string SVG_StringFormat() override;
};

#endif //SVG_CIRCLE_H
