//
// Created by User on 3.6.2019 г..
//

#ifndef SVG_SVG_CONTENTSTORAGE_H
#define SVG_SVG_CONTENTSTORAGE_H

#include <vector>
#include <string>

enum Option{ON_OPEN, ADD};

class ContentStorage
{
private:
    std::vector<std::string> svgContent;
public:
    ContentStorage();
    explicit ContentStorage(const std::vector<std::string>&);

    void SetContent(const std::vector<std::string>&, Option);
    std::vector<std::string> GetContent();

    ~ContentStorage();
};

#endif //SVG_SVG_CONTENTSTORAGE_H
