//
// Created by User on 4.6.2019 г..
//

#ifndef SVG_SAVE_H
#define SVG_SAVE_H

#include "CommandType.h"

class Save : public CommandType
{
    public:
        Save(FileStream*, ContentStorage*, FigureStorage*);
        bool Execute() override;
};

#endif //SVG_SAVE_H
