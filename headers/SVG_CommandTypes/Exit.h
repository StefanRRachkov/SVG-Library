//
// Created by User on 4.6.2019 г..
//

#ifndef SVG_EXIT_H
#define SVG_EXIT_H

#include "CommandType.h"

class Exit : public CommandType
{
    public:
        Exit(FileStream*, ContentStorage*, FigureStorage*);
        bool Execute() override;
};

#endif //SVG_EXIT_H
