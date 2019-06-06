//
// Created by User on 3.6.2019 г..
//

#include "../headers/SVG_ContentStorage.h"
#include <iostream>

ContentStorage::ContentStorage() = default;

ContentStorage::ContentStorage(const std::vector<std::string>& content)
{
    this -> svgContent = content;
}

void ContentStorage::SetContent(const std::vector<std::string>& content, Option toDo)
{
    switch (toDo)
    {
        case ON_OPEN:
        {
            this -> svgContent = content;
            break;
        }
        case ADD:
        {
            for(const auto& svgFigure : content)
            {
                this -> svgContent.push_back(svgFigure);
            }
            break;
        }
        default: break;
    }
}

std::vector<std::string> ContentStorage::GetContent()
{
    return this -> svgContent;
}

ContentStorage::~ContentStorage()
{
    svgContent.clear();
}
