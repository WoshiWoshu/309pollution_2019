#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Utility.hpp"
#include "Pollution.hpp"

static void displayHelp(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./309pollution n file x y" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tn\tnumber of points on the grid axis" << std::endl;
    std::cout << "\tfile\tcsv file containing the data points x;y;p"
    << std::endl;
    std::cout << "\tx\tabscissa of the point whose pollution level we want to know" << std::endl;
    std::cout << "\ty\tordinate of the point whose pollution level we want to know" << std::endl;
}

int main(int ac, char **av)
{

    int n(0);
    double x(0);
    double y(0);

    if (ac == 2 and strcmp(av[1], "-h") == 0)
        displayHelp();
    else if (ac == 5) {
        if (!checkError(av))
            return (84);
        n = atoi(av[1]);
        x = atof(av[3]);
        y = atof(av[4]);
        if (!pollution(n, av[2], x, y))
            return (84);
    } else {
        std::cerr << "[ERROR] Bad argument(s)" << std::endl;
        return (84);
    }
    return (0);
}
