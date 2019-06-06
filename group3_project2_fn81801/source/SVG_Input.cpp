//
// Created by User on 22.04.2019 г..
//

#include "../headers/SVG_Input.h"


Input::Input() = default;

Input::Input(const Input& rightInput)
{
    this -> userInput = rightInput.userInput;
}

void Input::SetUserInput()
{

}

string Input::GetUserInput()
{
    return this -> userInput;
}

void Input::SetUserInput(const std::string& user)
{
    this -> userInput = user;
}

Input::~Input()
{
    this -> userInput.clear();
}


