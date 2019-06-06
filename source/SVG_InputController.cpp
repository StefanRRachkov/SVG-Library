//
// Created by User on 09.05.2019 г..
//

#include "../headers/SVG_InputController.h"

InputController::InputController()
{
    this -> inputCommand = nullptr;
}


InputController::InputController(Input* user, FileStream* file, ContentStorage* content, FigureStorage* figures)
{
    this -> SetUserInput(user, file, content, figures);
}

InputController::InputController(const InputController& rightController)
{
    this -> userInput = rightController.userInput;
    this -> inputCommand = rightController.inputCommand;
}


InputController InputController::operator=(const InputController& rightController)
{
    return InputController(rightController.userInput, rightController.inputCommand -> GetFile(), rightController.inputCommand -> GetContent(), rightController.inputCommand -> GetFigures());
}

void InputController::SetUserInput(Input* user, FileStream* file, ContentStorage* content, FigureStorage* figures)
{
    this -> userInput = user;
    if(this -> userInput -> GetUserInput().find("open") != std::string::npos)
    {
        auto* userIn = new std::string;
        *userIn =  this -> userInput -> GetUserInput();
        userIn -> erase(0, 5);
        this -> userInput -> SetUserInput(*userIn);
        this -> inputCommand = new Open(file, content, figures);
        delete(userIn);
    }
    else if(this -> userInput -> GetUserInput().find("print") != std::string::npos)
    {
        this -> inputCommand = new Print(file, content, figures);
    }
    else if(this -> userInput -> GetUserInput().find("save") != std::string::npos)
    {
        this -> inputCommand = new Save(file, content, figures);
    }
    else if(this -> userInput -> GetUserInput().find("exit") != std::string::npos)
    {
        this -> inputCommand = new Exit(file, content, figures);
    }
    else if(this -> userInput -> GetUserInput().find("create") != std::string::npos)
    {
        auto* userIn = new std::string;
        *userIn =  this -> userInput -> GetUserInput();
        userIn -> erase(0, 7);
        this -> userInput -> SetUserInput(*userIn);
        this -> inputCommand = new Create(file, content, figures);
        delete(userIn);
    }
    else if(this -> userInput -> GetUserInput().find("erase") != std::string::npos)
    {
        auto* userIn = new std::string;
        *userIn =  this -> userInput -> GetUserInput();
        userIn -> erase(0, 6);
        this -> userInput -> SetUserInput(*userIn);
        this -> inputCommand = new Erase(file, content, figures);
        delete(userIn);
    }
    else if(this -> userInput -> GetUserInput().find("translate") != std::string::npos)
    {
        auto* userIn = new std::string;
        *userIn =  this -> userInput -> GetUserInput();
        userIn -> erase(0, 9);
        this -> userInput -> SetUserInput(*userIn);
        this -> inputCommand = new Translate(file, content, figures);
        delete(userIn);
    }
    else if(this -> userInput -> GetUserInput().find("within") != std::string::npos)
    {
        auto* userIn = new std::string;
        *userIn =  this -> userInput -> GetUserInput();
        userIn -> erase(0, 7);
        this -> userInput -> SetUserInput(*userIn);
        this -> inputCommand = new Within(file, content, figures);
        delete(userIn);
    }
}

Input* InputController::GetInput()
{
    return this -> userInput;
}

CommandType* InputController::GetCommand()
{
    return this -> inputCommand;
}

InputController::~InputController()
{
    delete(inputCommand);
}

