/**
 * @file command.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include "argparse.hpp"
#include "rfo.hpp"
#include <cstring>

namespace command
{

    int process(argparse::arguments *_args)
    {
        // get file information
        if (strcmp(_args->_action, "-info") == 0)
        {
            auto _out = rfo::initiateStat(_args->_fname);
            if (_out.first not_eq -1)
                utils::displayStats(_out.second);
            return _out.first == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
        }
        // open a file
        else if (strcmp(_args->_action, "-open") == 0)
        {
            int _fd = rfo::initiateOpen(_args->_fname, _args->_opt1);
            if (_fd not_eq -1)
            {
                _fd = rfo::initiateClose(_fd);
            }
            return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
        }
        // read a file
        else if (strcmp(_args->_action, "-read") == 0)
        {
            int _fd = rfo::initiateOpen(_args->_fname, "-rd");
            if (_fd == -1)
            {
                std::cout << "\nError reading file !\n";
                return EXIT_FAILURE;
            }

            std::size_t _nbytes = atoi(_args->_opt1);
            char _buffer[_nbytes];
            off_t _offset = atoi(_args->_opt2);
            auto _nbytesread = rfo::initiateRead(_fd, _buffer, _nbytes, _offset);
            if (_nbytes > 0)
                utils::printBuffer(_buffer, _nbytesread);
            if (_fd not_eq -1)
            {
                _fd = rfo::initiateClose(_fd);
            }
            return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
        }
        // write to a file
        else if (strcmp(_args->_action, "-write") == 0)
        {
            int _fd = rfo::initiateOpen(_args->_fname, "-wr");
            if (_fd == -1)
            {
                std::cout << "\nError reading file !\n";
                return EXIT_FAILURE;
            }
            char *_buffer;
            off_t _offset = atoi(_args->_opt1);
            auto _nbyteswr = rfo::initiateWrite(_fd, _buffer, _offset);
            if (_nbyteswr == -1)
            {
                std::cout << "\nError writing to file !";
            }
            else if (_nbyteswr > 0)
            {
                std::cout << "\nModified file content :\n";
                std::string _file = "cat ";
                _file.append(_args->_fname);
                system(_file.c_str());
            }
            if (_fd not_eq -1)
            {
                _fd = rfo::initiateClose(_fd);
            }
            return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
        }
        // create a file
        else if (strcmp(_args->_action, "-create") == 0)
        {
            auto _out = rfo::initiateStat(_args->_fname);
            if (_out.first not_eq -1)
            {
                std::cout << "\nFile already exists !";
                return EXIT_FAILURE;
            }
            mode_t _mode;
            if (strcmp(_args->_opt1, "") == 0)
                _mode = 0666;
            else
            _mode=utils::toMode(_args->_opt1);
                // _mode = utils::toMode(_args->_opt1);
            int _fd = rfo::initiateCreate(_args->_fname, _mode);
            return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
        }
        return 0;
    }
} // namespace command