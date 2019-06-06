//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_OPEN_H
#define SVG_OPEN_H

#include "CommandType.h"

class Open : public CommandType
{
    public:
        Open(FileStream*, ContentStorage*, FigureStorage*);
        void Execute(const std::string&) override;
};

#endif //SVG_OPEN_H
