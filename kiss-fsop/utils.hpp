/**
 * @file utils.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <iso646.h>
#include <vector>
#include "constants.hpp"
#include "sys/stat.h"

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

namespace utils
{
    bool isValidFileType(const char *_ftype)
    {
        if (validator::_filetype.find(_ftype) not_eq validator::_filetype.end()) // O(log n)
            return true;                                                         // valid filetype
        return false;                                                            // invalid filetype
    }

    bool isValidAction(const char *_action)
    {
        if (validator::_action.find(_action) not_eq validator::_action.end())
            return true;
        return false;
    }

    bool isValidPermission(const char *_permission)
    {
        if (validator::_permissions.find(_permission) not_eq validator::_permissions.end())
            return true;
        return false;
    }
    /**
     * @brief function to display file information
     *
     * @param _fileStats
     */
    void displayStats(struct stat _fileStats)
    {
        std::cout << "\n-----File information-----";
        std::cout << "\nFile st_uid : " << _fileStats.st_uid;
        std::cout << "\nFile st_gid : " << _fileStats.st_gid;
        std::cout << "\nFile st_blksize : " << _fileStats.st_blksize;
        std::cout << "\nFile st_blocks : " << _fileStats.st_blocks;
        std::cout << "\nFile st_size : " << _fileStats.st_size;
        std::cout << "\nFile st_nlink : " << (unsigned int)_fileStats.st_nlink;

        std::cout << "\nFile permissions for user : ";
        printf((_fileStats.st_mode & S_IRUSR) ? "r" : "-");
        printf((_fileStats.st_mode & S_IWUSR) ? "w" : "-");
        printf((_fileStats.st_mode & S_IXUSR) ? "x" : "-");

        std::cout << "\nFile permissions for group : ";
        printf((_fileStats.st_mode & S_IRGRP) ? "r" : "-");
        printf((_fileStats.st_mode & S_IWGRP) ? "w" : "-");
        printf((_fileStats.st_mode & S_IXGRP) ? "x" : "-");

        std::cout << "\nFile permissions for others : ";
        printf((_fileStats.st_mode & S_IROTH) ? "r" : "-");
        printf((_fileStats.st_mode & S_IWOTH) ? "w" : "-");
        printf((_fileStats.st_mode & S_IXOTH) ? "x" : "-");
        return;
    }

    void printBuffer(const char *_buffer, ssize_t _nbytes)
    {
        std::cout << "\nBuffer content :\n";
        for (auto it = 0; it < _nbytes; it++)
            std::cout << _buffer[it];
        std::cout << std::endl;
        return;
    }

    mode_t toMode(const char *_perm)
    {
        mode_t _mode = 0000;
        if (_perm[0] == 'r')
            _mode |= S_IRUSR;
        if (_perm[1] == 'w')
            _mode |= S_IWUSR;
        if (_perm[2] == 'x')
            _mode |= S_IXUSR;
        // _mode = _mode << 3;
        if (_perm[3] == 'r')
            _mode |= S_IRGRP;
        if (_perm[4] == 'w')
            _mode |= S_IWGRP;
        if (_perm[5] == 'x')
            _mode |= S_IXGRP;
        // _mode = _mode << 3;
        if (_perm[6] == 'r')
            _mode |= S_IROTH;
        if (_perm[7] == 'w')
            _mode |= S_IWOTH;
        if (_perm[8] == 'x')
            _mode |= S_IXOTH;
            std::cout<<"\n mode "<<std::oct<<_mode<<" \n";
        return _mode;
    }
} // namespace utils

#endif