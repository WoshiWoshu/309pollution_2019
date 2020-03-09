#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#include "Utility.hpp"

bool isPosNum(const std::string &str)
{
    std::string::const_iterator itStr =
    std::find_if(str.begin(), str.end(), [](const char c) { return
    !std::isdigit(c); });

    return itStr == str.end();
}

static bool isFloatNum(char *buff)
{
    for (int i = 0; buff[i] != '\0'; ++i)
        if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '.')
            return FAILURE;
    if (strcmp(buff, ".") == 0)
        return FAILURE;
    return SUCCESS;
}

bool checkError(char **av)
{
    int n = atoi(av[1]);
    int x = atoi(av[3]);
    int y = atoi(av[4]);

    if (!isPosNum(av[1]) || !isFloatNum(av[3]) || !isFloatNum(av[4])) {
        std::cerr << "[ERROR] Bad input(s)" << std::endl;
        return FAILURE;
    }
    if (x > n - 1 || y > n - 1 || n < 2) {
        std::cerr << "[ERROR] Number(s) out of range" << std::endl;
        return FAILURE;
    }
    return SUCCESS;
}
