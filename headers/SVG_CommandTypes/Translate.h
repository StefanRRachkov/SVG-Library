//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_TRANSLATE_H
#define SVG_TRANSLATE_H

#include "CommandType.h"
#include <regex>

class Translate : public CommandType
{
    public:
        Translate(FileStream*, ContentStorage*, FigureStorage*);
        void Execute(const std::string&) override;
};

#endif //SVG_TRANSLATE_H
