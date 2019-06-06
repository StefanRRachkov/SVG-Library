//
// Created by User on 09.05.2019 г..
//

#include "../headers/SVG_UInterface.h"

UInterface::UInterface() = default;

void UInterface::Handle(const std::string& commandMessage)
{
    this -> stream = commandMessage;
}

void UInterface::Draw()
{
    std::cout << this -> stream;
}


