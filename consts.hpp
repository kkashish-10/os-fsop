/**
 * @file consts.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <unordered_map>
#include <string>
#include <fcntl.h>
#ifndef _CONSTS_HPP_
#define _CONSTS_HPP_

namespace consts
{
    std::unordered_map<std::string, int> _oflag = {
        {"-rd", O_RDONLY},
        {"-wr", O_WRONLY},
        {"-rdwr", O_RDWR}};

    mode_t mapToMode(const char *_permissions)
    {
        
        
        return S_IRUSR;
    }
} // namespace consts

#endif