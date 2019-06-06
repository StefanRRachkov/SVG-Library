//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_CREATE_H
#define SVG_CREATE_H

#include "CommandType.h"
#include <regex>

class Create : public CommandType
{
    public:
        Create(FileStream*, ContentStorage*, FigureStorage*);
        void Execute(const std::string&) override;
};

#endif //SVG_CREATE_H
