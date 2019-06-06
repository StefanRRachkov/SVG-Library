//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_ERASE_H
#define SVG_ERASE_H

#include "CommandType.h"

class Erase : public CommandType
{
    public:
        Erase(FileStream*, ContentStorage*, FigureStorage*);
        void Execute(const std::string&) override;
};


#endif //SVG_ERASE_H
