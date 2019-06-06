//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_COMMANDTYPE_H
#define SVG_COMMANDTYPE_H

#include "../SVG_FileStream.h"
#include "../SVG_ContentStorage.h"
#include "../SVG_FigureStorage.h"

void ExtractSequenceOfNumbers(std::string, std::vector<double>*);

class CommandType
{
    protected:
        FileStream* file;
        ContentStorage* svgContent;
        FigureStorage* figureContainer;

        std::string message;
    public:
        CommandType();
        CommandType(FileStream*, ContentStorage*, FigureStorage*);
        CommandType(const CommandType&);

        virtual void Execute(const std::string&);
        virtual bool Execute();
        std::string GetMessage();

        FileStream* GetFile();
        ContentStorage* GetContent();
        FigureStorage* GetFigures();

        ~CommandType();
};

#endif //SVG_COMMANDTYPE_H
