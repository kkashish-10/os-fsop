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
#include "fsop.hpp"
#include <cstring>

namespace command
{

    int process(argparse::arguments *_args)
    {
        if (strcmp(_args->_action, "-info") == 0)
        {
            auto _out = fsop::initiateStat(_args->_fname);
            if (_out.first not_eq -1)
                utils::displayStats(_out.second);
            return _out.first == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
        }
        if (strcmp(_args->_ftype, "-rf") == 0)
        {
            // open a file
            if (strcmp(_args->_action, "-open") == 0)
            {
                int _fd = regfile::initiateOpen(_args->_fname, _args->_opt1);
                if (_fd not_eq -1)
                {
                    _fd = fsop::initiateClose(_fd);
                }
                return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
            }
            // read a file
            else if (strcmp(_args->_action, "-read") == 0)
            {
                int _fd = regfile::initiateOpen(_args->_fname, "-rd");
                if (_fd == -1)
                {
                    std::cout << "\nError reading file !\n";
                    return EXIT_FAILURE;
                }

                std::size_t _nbytes = atoi(_args->_opt1);
                char _buffer[_nbytes];
                off_t _offset = atoi(_args->_opt2);
                auto _nbytesread = fsop::initiateRead(_fd, _buffer, _nbytes, _offset);
                if (_nbytes > 0)
                    utils::printBuffer(_buffer, _nbytesread);
                if (_fd not_eq -1)
                {
                    _fd = fsop::initiateClose(_fd);
                }
                return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
            }
            // write to a file
            else if (strcmp(_args->_action, "-write") == 0)
            {
                int _fd = regfile::initiateOpen(_args->_fname, "-wr");
                if (_fd == -1)
                {
                    std::cout << "\nError reading file !\n";
                    return EXIT_FAILURE;
                }
                char *_buffer;
                off_t _offset = atoi(_args->_opt1);
                auto _nbyteswr = fsop::initiateWrite(_fd, _buffer, _offset);
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
                    _fd = fsop::initiateClose(_fd);
                }
                return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
            }
            // create a file
            else if (strcmp(_args->_action, "-create") == 0)
            {
                auto _out = fsop::initiateStat(_args->_fname);
                if (_out.first not_eq -1)
                {
                    std::cout << "\nFile already exists !";
                    return EXIT_FAILURE;
                }
                mode_t _mode;
                if (strcmp(_args->_opt1, "") == 0)
                    _mode = 0777;
                else
                    _mode = utils::toMode(_args->_opt1);
                int _fd = regfile::initiateCreate(_args->_fname, _mode);
                return _fd == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
            }
        }
        else if (strcmp(_args->_ftype, "-np") == 0)
        {
            if (strcmp(_args->_action, "-create") == 0)
            {
                if (strcmp(_args->_fname, "") == 0)
                {
                    std::cout << "\nError creating named pipe ! Pipe name not given !";
                    return EXIT_FAILURE;
                }
                auto _rvalue = npipe::initiateCreate(_args->_fname);
                std::cout << (_rvalue == EXIT_SUCCESS ? "Successfully created pipe !" : "Error creating pipe !");
                return _rvalue;
            }
            else if (strcmp(_args->_action, "-read") == 0)
            {
                auto _fd = npipe::initiateOpen(_args->_fname, O_RDONLY);
                if (_fd == -1)
                    return EXIT_FAILURE;
                char _buffer[1024];
                while (true)
                {
                    fsop::initiateRead(_fd, _buffer, 8);
                }
            }
            else if (strcmp(_args->_action, "-write") == 0)
            {
                auto _fd = npipe::initiateOpen(_args->_fname, O_WRONLY);
                if (_fd == -1)
                    return EXIT_FAILURE;
                char _buffer[1024];
                while (true)
                {
                    fsop::initiateWrite(_fd, _buffer, 8);
                }
            }
        }
        else
        {
            std::cout << "\nCommand not found !\n./fsop  or -/fsop --help for usage !";
            return EXIT_FAILURE;
        }
        return 0;
    }

    auto process_unp(argparse::arguments *_args)
    {
        if (strcmp(_args->_ftype, "-unp") == 0)
        {
            int _fd[2];
            if (strcmp(_args->_action, "-create") == 0)
            {
                auto _out = unpipe::initiateCreate(_fd);
                char *_buffer;
                auto _nbytes = -1;
                while (true)
                {
                    _nbytes = fsop::initiateWrite(_fd[1], _buffer);
                    fsop::initiateRead(_fd[0], _buffer, 8);
                }
                return _out;
            }
        }
        else
        {
            std::cout << "\nCommand not found !\n./fsop  or -/fsop --help for usage !";
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
} // namespace command