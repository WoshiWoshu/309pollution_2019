#pragma once

#include <string>

static const int X = 30;
static const int Y = 30;

bool checkError(char **av);
bool parseFile(const std::string &file,
    int coordinates[X][Y]);
bool pollution(int n, const std::string &file, double x, double y);
