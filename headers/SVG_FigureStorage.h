//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_SVG_FIGURESTORAGE_H
#define SVG_SVG_FIGURESTORAGE_H

#include "../figures/Figures.h"

std::vector<Figure*> ParseFromString(const std::vector<std::string>&);

class FigureStorage
{
private:
    std::vector<Figure*> svgFigure;
public:
    FigureStorage();
    explicit FigureStorage(const std::vector<Figure*>&);

    void LoadFigures(const std::vector<Figure*>&);
    void DeleteFigures(unsigned int);
    std::vector<Figure*> GetFigures();
    std::vector<std::string> GetFormatSVG();

    ~FigureStorage();
};

#endif //SVG_SVG_FIGURESTORAGE_H
