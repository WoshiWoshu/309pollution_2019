#include <fstream>
#include <iostream>
#include "Utility.hpp"
#include "Pollution.hpp"

static bool parseCoordinates(std::string line,
    int coordinates[X][Y])
{
    std::string delimiter(";");
    size_t pos(0);
    std::string token("");
    int counter(0);
    int tmpCoordinates[2];

    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        if (!isPosNum(token) || token.empty()) {
            std::cerr << "[ERROR] Bad number(s)" << std::endl;
            return FAILURE;
        }
        line = line.substr(pos + delimiter.length());
        tmpCoordinates[counter] = std::stoi(token);
        counter++;
    }
    if (counter != 2 || !isPosNum(line)) {
        std::cerr << "[ERROR] File corrupted" << std::endl;
        return FAILURE;
    }
    coordinates[tmpCoordinates[0]][tmpCoordinates[1]] = std::stoi(line);
    return SUCCESS;
}

bool parseFile(const std::string &file,
    int coordinates[X][Y])
{
    std::ifstream fileStream(file);
    std::string line;

    if (!fileStream) {
        std::cerr << "[ERROR] Can't open the file" << std::endl;
        return FAILURE;
    }
    while (getline(fileStream, line)) {
        if (!parseCoordinates(line, coordinates))
            return FAILURE;
    }
    return SUCCESS;
}
