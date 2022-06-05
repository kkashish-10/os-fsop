/**
 * @file constants.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <set>
#include <string>
#include <fcntl.h>
#include <unordered_map>

#ifndef _CONSTANTS_HPP_
#define _CONSTANTS_HPP_

namespace validator
{
    std::set<std::string> _filetype = {"-dir", "-rf", "-np", "-unp"};
    std::set<std::string> _action = {"-open", "-read", "-write", "-create", "-info"};
    std::set<std::string> _permissions = {"-rd", "-wr", "rdwr"};

} // namespace validator

namespace flags
{
    std::unordered_map<std::string, int> _oflag = {
        {"-rd", O_RDONLY},
        {"-wr", O_WRONLY},
        {"-rdwr", O_RDWR}};
} // namespace flags

#endif