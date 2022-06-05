#include <stdlib.h>
#include <iostream>
#include "constants.hpp"
#include "argparse.hpp"
#include "utils.hpp"
#include "command.hpp"

int main(const int argc, const char **argv)
{
    srand(time(0));
    if (argc <= 2)
    {
        system("cat blueprint.hpp");
        return -1;
    }
    argparse::arguments *_args = new argparse::arguments(argc, argv);
    // argparse::displayArgs(_args);
    // if (argc == 3)
    // {
    //     return EXIT_SUCCESS;
    // }
    if (argc >= 3)
    {
        auto _rvalue = command::process(_args);
    }
    // return exit success everything went smooth
    std::cout << std::endl;
    return EXIT_SUCCESS;
}