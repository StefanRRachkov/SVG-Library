//
// Created by User on 22.04.2019 г..
//

#ifndef SVG_SVG_INPUT_H
#define SVG_SVG_INPUT_H

#include <string>

using namespace std;

class Input
{
    protected:
        string userInput;
    public:
        Input();
        Input(const Input&);

        virtual void SetUserInput();
        void SetUserInput(const std::string&);
        string GetUserInput();

        ~Input();
};

#endif //SVG_SVG_INPUT_H
