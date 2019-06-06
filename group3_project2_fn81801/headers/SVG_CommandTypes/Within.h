//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_WITHIN_H
#define SVG_WITHIN_H

#include "CommandType.h"
#include <regex>
#include <cmath>

class Within : public CommandType
{
    public:
        Within(FileStream*, ContentStorage*, FigureStorage*);
        void Execute(const std::string&) override;
};

#endif //SVG_WITHIN_H
