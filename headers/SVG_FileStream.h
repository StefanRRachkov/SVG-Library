//
// Created by User on 3.6.2019 г..
//
#ifndef SVG_SVG_FILESTREAM_H
#define SVG_SVG_FILESTREAM_H

#include <fstream>
#include <string>
#include <vector>

class FileStream
{
private:
    std::fstream svgFile;
    std::string fileName;
public:
    FileStream();
    explicit FileStream(const std::string&);

    bool Open(const std::string&);
    void Save(const std::vector<std::string>&);
    std::vector<std::string> Read();
    std::string GetFilePath();

    ~FileStream();
};

#endif //SVG_SVG_FILESTREAM_H
