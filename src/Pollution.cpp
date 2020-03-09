#include <math.h>
#include <iostream>
#include <iomanip>
#include "Utility.hpp"
#include "Pollution.hpp"

static long factorial(int number)
{
    if (number == 0)
        return 1;
    else
        return number * factorial(number - 1);
}

static double newtonCoeff(int n, int k)
{
    double coeff = factorial(n) / static_cast<double>(factorial(k) * factorial(n - k));

    return coeff;
}

static double computeT(int n, double xy, int k)
{
    double t(xy / n);
    double result(1);

    result = pow(t, k) * pow(1 - t, n - k);
    return result;
}

static double bezierArea(int n, int coordinates[X][Y], double x, double y)
{
    double result(0);

    for (int k1 = 0; k1 <= n; k1++) {
        for (int k2 = 0; k2 <= n; k2++) {
            result += newtonCoeff(n, k1) * newtonCoeff(n, k2)
            * computeT(n, x, k1) * computeT(n, y, k2) * coordinates[k1][k2];
        }
    }
    return result;
}

bool pollution(int n, const std::string &file, double x, double y)
{
    int coordinates[X][Y] = {{0}};
    double result(0);

    if (!parseFile(file, coordinates))
        return FAILURE;
    result = bezierArea(n - 1, coordinates, x, y);
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    return SUCCESS;
}
