//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_PRINT_H
#define SVG_PRINT_H

#include "CommandType.h"

class Print : public CommandType
{
    public:
        Print(FileStream*, ContentStorage*, FigureStorage*);
        bool Execute() override;
};

#endif //SVG_PRINT_H
