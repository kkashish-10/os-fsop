/**
 * @file rfo.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <utility>
#include <sys/stat.h>
#include <unistd.h>
#include <exception>
#include <iostream>
#include <fcntl.h>
#include <cstring>

#ifndef _RFO_HPP_
#define _RFO_HPP_

namespace rfo
{
    /**
     * @brief function to get meta data for a file
     *
     * @param _file file
     * @return std::pair<int, struct stat>
     */
    std::pair<int, struct stat> initiateStat(const char *_file)
    {
        struct stat _fileStats;
        int _fd = -1;
        try
        {
            _fd = stat(_file, &_fileStats);
            if (_fd == -1)
            {
                std::cout << "\nFile does not exist ! Create file first !\n";
                return {_fd, _fileStats};
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return {_fd, _fileStats};
    }

    /**
     * @brief function to initiate opening of a file
     *
     * @param _file file
     * @param _oflag opening flag
     * @return int
     */
    int initiateOpen(const char *_file, const int _oflag)
    {
        int _fd = -1;
        std::pair<int, struct stat> _fileStats = initiateStat(_file);
        if (_fileStats.first == -1)
        {
            std::cout << "\nSome error occured ! Please retry !\n";
            return _fileStats.first;
        }
        else if (_fileStats.first == 0)
        {
            std::cout << "\nFile Exists ! Trying to open the file !\n";
            if (_oflag == O_RDONLY)
            {
                if (_fileStats.second.st_mode & S_IREAD)
                {
                    _fd = open(_file, _oflag);
                    std::cout << (_fd == -1 ? "\nError opening file !" : "\nFile opened successfully !\n");
                    return _fd;
                }
                std::cout << "\nError opening file ! Permission denied !\n";
                return _fd;
            }
            else if (_oflag == O_WRONLY)
            {
                if (_fileStats.second.st_mode & S_IWRITE)
                {
                    _fd = open(_file, _oflag);
                    std::cout << (_fd == -1 ? "\nError opening file !" : "\nFile opened successfully !\n");
                    return _fd;
                }
                std::cout << "\nError opening file ! Permission denied!\n";
                return _fd;
            }
            else if (_oflag == O_RDWR)
            {
                if ((_fileStats.second.st_mode & S_IREAD) and _fileStats.second.st_mode & S_IWRITE)
                {
                    if (_fileStats.second.st_mode & S_IWRITE)
                    {
                        _fd = open(_file, _oflag);
                        std::cout << (_fd == -1 ? "\nError opening file !" : "\nFile opened successfully !\n");
                        return _fd;
                    }
                    std::cout << "\nError opening file ! Permission denied!\n";
                    return _fd;
                }
            }
        }
        return _fd;
    }

    // ssize_t initiateRead(const char* _file,)
    // {
    //     //for reading we need to open the file and that requires initatestat to check if the file exists
    //     int _fd=initiateOpen(_file,O_RDONLY);
    //     // if(_fd==-1)
    //     // read(_fd,_buffer,_nbytes);
            
    // }
}
#endif //_RFO_HPP_