/**
 * @file argparse.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <string>
#ifndef _ARGPARSE_HPP_
#define _ARGPARSE_HPP_

namespace arg
{
    struct arguments
    {
        const char *_action;
        const char *_ftype;
        const char *_fname;
        const char *_permissions;
        arguments(){};
        arguments(const int &argc, const char **argv)
        {
            _action = argv[1], _ftype = argv[2];
            _fname = argc >= 4 ? argv[3] : "";
            _permissions = argc == 5 ? argv[4] : "";
        };
    };

} // namespace  arg

#endif
