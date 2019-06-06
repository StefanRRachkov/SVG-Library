//
// Created by User on 09.05.2019 г..
//

#ifndef SVG_SVG_UINTERFACE_H
#define SVG_SVG_UINTERFACE_H

#include "SVG_Interface.h"

class UInterface : public Interface
{
    public:
        UInterface();

        void Handle(const std::string&) override;
        void Draw() override;
};

#endif //SVG_SVG_UINTERFACE_H
