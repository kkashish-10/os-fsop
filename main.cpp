#include "utils.hpp"
#include <stdlib.h>

void disArgs(const arg::arguments *args)
{
    std::cout << " action " << args->_action;
    std::cout << "\n type " << args->_ftype;
    std::string temp = args->_fname;
    if (temp != "")
    {
        std::cout << "\n fname " << args->_fname;
        temp = args->_permissions;
        if (temp != "")
            std::cout << "\n perm " << args->_permissions;
    }
    return;
}

/**
 * @brief driver function of the program
 *
 * @param argc count of arguments taken from command line
 * @param argv argument vector taken from command line
 * @return int type exit status 0 for success, 1 for failure
 */
int main(const int argc, const char **argv)
{
    if (argc == 1 or argc == 2 or (argc == 3 and strcmp(argv[2], "-up") not_eq 0) or (argc == 4 and strcmp(argv[2], "-up") == 0))
    {
        utils::initHelp();
        return EXIT_FAILURE;
    }
    if (argc > 5)
    {
        std::cout << "\nToo many arguments !\n";
        utils::initHelp();
        return EXIT_FAILURE;
    }
    arg::arguments *_args = new arg::arguments(argc, argv);
    if (argc == 3 and strcmp(_args->_ftype, "-up") == 0)
    {
        std::cout << "\n Named Pipe operation";
    }
    if (argc >= 4)
    {
        utils::initiate(_args);
    }
    return EXIT_SUCCESS;
}
