/**
 * @file main.cpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

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
        system("cat ../help.txt");
        return -1;
    }
    argparse::arguments *_args = new argparse::arguments(argc, argv);
    if (argc == 3 and strcmp(_args->_ftype, "-unp") == 0)
    {
        auto _rvalue = command::process_unp(_args);
    }
    else if (argc > 3 and argc <= 6)
        auto _rvalue = command::process(_args);
    // return exit success everything went smooth
    else
    {
        std::cout << "\nInvalid Arguments !\n./fsop or ./fsop --help for usage !";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}