/**
 * @file utils.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "consts.hpp"
#include "rfo.hpp"
#include "argparse.hpp"
#ifndef _UTILS_HPP_
#define _UTILS_HPP_

namespace utils
{
    /**
     * @brief
     *
     */
    void initHelp()
    {
        system("cat readme.txt");
        return;
    }

    void initiate(arg::arguments *_args)
    {
        if (strcmp(_args->_ftype, "-rf") == 0)
        {
            int _fd = -1;
            ssize_t _nbytesread = -1;
            if (strcmp(_args->_action, "-op") == 0)
            {
                if (strcmp(_args->_permissions, "") == 0)
                    _args->_permissions = "-rd";
                else if (consts::_oflag.find(_args->_permissions) == consts::_oflag.end())
                {
                    std::cout << "\nError opening file invalid opening flag!\n";
                    initHelp();
                    return;
                }
                _fd = rfo::initiateOpen(_args->_fname, consts::_oflag[_args->_permissions]);
            }
            else if (strcmp(_args->_action, "-rd") == 0)
            {
                _nbytesread=rfo::initiateRead(_args->_fname,)
            }
        }

        return;
    }
}

#endif


//open function done 