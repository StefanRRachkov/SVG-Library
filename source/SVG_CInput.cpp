//
// Created by User on 22.04.2019 г..
//

#include "../headers/SVG_CInput.h"

CInput::CInput() = default;

void CInput::SetUserInput()
{
    std::getline(std::cin, this -> userInput);
}
