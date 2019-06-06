//
// Created by User on 22.04.2019 г..
//

#ifndef SVG_SVG_CINPUT_H
#define SVG_SVG_CINPUT_H

#include "SVG_Input.h"
#include <iostream>

class CInput : public Input
{
    public:
        CInput();

        void SetUserInput() override;
};

#endif //SVG_SVG_CINPUT_H
