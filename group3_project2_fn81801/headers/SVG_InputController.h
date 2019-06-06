//
// Created by User on 09.05.2019 г..
//
#ifndef SVG_SVG_INPUTCONTROLLER_H
#define SVG_SVG_INPUTCONTROLLER_H

#include "SVG_Input.h"
#include "SVG_Commands.h"

class InputController
{
    private:
        Input* userInput;
        CommandType* inputCommand;
    public:
        InputController();
        InputController(Input*, FileStream*, ContentStorage*, FigureStorage*);
        InputController(const InputController&);

        InputController operator=(const InputController&);

        void SetUserInput(Input*, FileStream* file, ContentStorage* content, FigureStorage* figures);

        Input* GetInput();
        CommandType* GetCommand();

        ~InputController();
};

#endif //SVG_SVG_INPUTCONTROLLER_H
