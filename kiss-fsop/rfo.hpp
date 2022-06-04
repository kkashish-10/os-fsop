/**
 * @file rfo.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iso646.h>
#include <utility>
#include <sys/stat.h>
#include <exception>
#include <iostream>
#include <unistd.h>
#include <cstring>
#ifndef _RFO_HPP_
#define _RFO_HPP_

namespace rfo
{
    /**
     * @brief function to get file stats
     *
     * @param _file
     * @return std::pair<int, struct stat>
     */
    std::pair<int, struct stat> initiateStat(const char *_file)
    {
        int _fd = -1;
        struct stat _fileStats;
        try
        {
            std::cout << "\nTrying to fetch file information !";
            _fd = stat(_file, &_fileStats);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << (_fd == -1 ? "\nError fetching file information !\n" : "\nSuccessfully fetched file information !");
        return {_fd, _fileStats};
    }

    /**
     * @brief function to open a file
     *
     * @param _file
     * @param _oflag
     * @return auto
     */
    auto initiateOpen(const char *_file, const char *_permissions)
    {
        std::cout << "\nTrying to open file !";
        if (strcmp(_permissions, "") == 0)
            _permissions = "-rd";
        if (not utils::isValidPermission(_permissions))
        {
            std::cout << "\nError opening file ! Invalid opening flag !";
            return -1;
        }
        auto _out = initiateStat(_file);

        try
        {
            if (_out.first not_eq 0)
            {
                std::cout << "\nFile does not exist ! Please create it first !";
                return -1;
            }
            // check if file has required permission
            int _oflag = flags::_oflag[_permissions]; // opening flag
            bool _pflag = false;                      // permissions flag
            if (_oflag == O_RDONLY and (_out.second.st_mode & S_IRUSR))
                _pflag = true;
            else if (_oflag == O_WRONLY and (_out.second.st_mode & S_IWUSR))
                _pflag = true;
            else if (_oflag == O_RDWR and (_out.second.st_mode & S_IRUSR) and (_out.second.st_mode & S_IWUSR))
                _pflag = true;
            if (not _pflag)
            {
                std::cout << "\nPermission denied !";
                return -1;
            }
            // file exists and has permissions
            _out.first = open(_file, _oflag);
            std::cout << (_out.first == -1 ? "\nError opening file !\n" : "\nSuccessfully opened file !");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return _out.first;
    }

    /**
     * @brief function to read from a file sequentially/randomly
     *
     * @param _fd
     * @param _buffer
     * @param _offset
     * @param _nbytes
     * @return auto
     */
    auto initiateRead(const int _fd, char *_buffer, const std::size_t _nbytes, off_t _offset = 0)
    {
        int _nbytesread = -1;
        try
        {
            lseek(_fd, _offset, SEEK_SET);
            _nbytesread = read(_fd, _buffer, _nbytes);
            if (_nbytesread == -1)
                std::cout << "\nError reading file !";
            else if (_nbytesread == 0)
                std::cout << "\nReached end of file !\n";
            else
                std::cout << "\nSuccessfully read " << _nbytesread << " bytes !";
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << "\n";
        }
        return _nbytesread;
    }

    auto initiateWrite(const int _fd, char *_buffer, off_t _offset = 0)
    {
        auto _nbyteswr = -1;
        try
        {
            lseek(_fd, _offset, SEEK_CUR);
            std::string _input;
            std::cout << "\nWhat would you like to write to the file :\n";
            getline(std::cin, _input);
            _buffer = &_input[0];
            _nbyteswr = write(_fd, _buffer, _input.size());
            if (_nbyteswr == -1)
                std::cout << "\nError writing to file !\n";
            else
                std::cout << "\nSuccessfully written " << _nbyteswr << " bytes to file !";
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return _nbyteswr;
    }

    auto initiateCreate(const char *_file, mode_t _mode = 0744)
    {
        auto _fd = -1;
        try
        {
            _fd = creat(_file, _mode);
            std::cout << (_fd == -1 ? "\nError creating file!" : "\nSuccessfully created file !");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return _fd;
    }
    auto initiateClose(const int _fd)
    {
        auto _out = -1;
        try
        {
            _out = close(_fd);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << (_out == -1 ? "\nError closing file !\n" : "\nSuccessfully closed file !\n");
        return _out;
    }

} // namespace rfo

#endif //_RFO_HPP_