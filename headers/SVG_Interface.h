//
// Created by User on 09.05.2019 г..
//
#ifndef SVG_SVG_INTERFACE_H
#define SVG_SVG_INTERFACE_H

#include <iostream>
#include <string>

class Interface
{
    protected:
        std::string stream;

    public:
        Interface();

        virtual void Handle(const std::string&);
        virtual void Draw();
};

#endif //SVG_SVG_INTERFACE_H
