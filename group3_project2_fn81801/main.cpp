#include "headers/SVG_InputController.h"
#include "headers/SVG_CInput.h"
#include "headers/SVG_UInterface.h"

int main ()
{
    CInput user;
    UInterface display;

    user.SetUserInput();

    auto* file = new FileStream;
    auto* content = new ContentStorage;
    auto* figures = new FigureStorage;
    auto* main_switch = new InputController;
    auto* over = new bool;
    *over = false;

    main_switch -> SetUserInput(&user, file, content, figures);
    main_switch -> GetCommand() -> Execute(user.GetUserInput());
    display.Handle(main_switch -> GetCommand() -> GetMessage());
    display.Draw();

    while(!*over)
    {
        user.SetUserInput();
        main_switch -> SetUserInput(&user, file, content, figures);
        *over = main_switch -> GetCommand() -> Execute();
        main_switch -> GetCommand() -> Execute(user.GetUserInput());
        display.Handle(main_switch -> GetCommand() -> GetMessage());
        display.Draw();
    }

    return 0;
}