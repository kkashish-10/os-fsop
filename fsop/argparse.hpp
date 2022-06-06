/**
 * @file argparse.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief file with functions and structure related with arguments passed on command line
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <string>
#include <iostream>

#ifndef _ARGPARSE_HPP_
#define _ARGPARSE_HPP_

namespace argparse
{
    struct arguments
    {
        const char *_action;
        const char *_ftype;
        const char *_fname;
        const char *_opt1;
        const char *_opt2;
        arguments(){};
        arguments(const int &argc, const char **argv)
        {
            _action = argv[1], _ftype = argv[2];
            _fname = argc >= 4 ? argv[3] : "";
            _opt1 = argc >= 5 ? argv[4] : "";
            _opt2 = argc == 6 ? argv[5] : "";
        };
    };

    /**
     * @brief helper function to display parsed arguments
     *
     * @param _args  pointer to arguments struct with parsed arguments
     */
    void displayArgs(arguments *_args)
    {
        std::cout << _args->_action << std::endl;
        std::cout << _args->_ftype << std::endl;
        if (_args->_fname)
            std::cout << _args->_fname << std::endl;
        if (_args->_opt1)
            std::cout << _args->_opt1 << std::endl;
        if (_args->_opt2)
            std::cout << _args->_opt2 << std::endl;
    }

} // namespace argparse

#endif