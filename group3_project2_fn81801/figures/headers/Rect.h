//
// Created by User on 14.05.2019 г..
//

#ifndef SVG_RECT_H
#define SVG_RECT_H

#include "SVG_Figure.h"

class Rect : public Figure
{
    private:
        double width, height;
    public:
        Rect(double, double, double, double);
        Rect& operator=(const Rect&);

        std::string ToString() override;
        std::string SVG_StringFormat() override;
};

#endif //SVG_RECT_H
