/**
 * @file blueprint.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief    command line program to operate on files, directories, named pipes and unnamed pipes
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */


/**
 * @brief command format
 * 
 * <program> [action] [filetype] [filename] [permissions/flags (optional)]
 *  0           1       2           3           4   
 */

/**
 * @brief regular files 
 * 
 * actions available - open,read,write or create
 *
 */

/**
 * @brief pipes unnamed
 * 
 * actions available - create
 * 
 */

/**
 * @brief  for open  action if no opening flag is specified default open flag will be read only
 * before opening check file existence 
 *      if file exists check permissions
 *          if permissions available then open
 *          else print Permissions denied ! and return -1000
 *  
 * 
 * 
 */

// ./testmain -read -rf blueprint.hpp  