/**
 * @file npo.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-06-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <sys/stat.h>
#include "utils.hpp"

#ifndef _NPO_HPP_
#define _NPO_HPP_

/**
 * @brief named pipes operations
 *
 */
namespace npo
{

    void initiateCreate(const char *_file, const char *_mode)
    {
        mknod(_file, utils::toMode(_mode), 0);
    }

} // namespace npo

#endif