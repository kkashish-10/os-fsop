/**
 * @file blueprint.hpp
 * @author ddos_kas (kd372744@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @brief
 *
 *
 * <program> <action> [filetype] [filename] [permissions]
 * 0            1       2           3           4
 *
 */



/*
    if only one or two argument(s) print readme file
    if three arguments unnamed pipe else print readme and EXIT_FAILURE
    if four arguments and not(-rf or -np) print readme and EXIT_FAILURE
    fifth argument is optional as if user doesn't provide fifth argument a defualt value will be used 
*/

/**
     * @brief
     *
     * @param _file path to file
     * @param _oflag opening flag
     * @return int type file descriptor
     */
    int initOpen(const char *_file, const int &_oflag)
    {
        int fd = -1;
        try
        {
            fd = open(_file, _oflag);
            // std::cout << " initopen fd "<<fd;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return fd;
    }

    /**
     * @brief
     *
     * @param _fd
     * @param _buf
     * @param _nbytes
     * @return int
     */
    int initRead(const int &_fd, char *_buf, unsigned _nbytes)
    {

        int _nbytesread = -1;
        try
        {
            _nbytesread = read(_fd, _buf, _nbytes);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return _nbytesread;
    }

    int initCreat(const char *_file, mode_t _mode)
    {
        int _fd = -1;
        try
        {
            _fd = creat(_file, _mode);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return _fd;
    }
    /**
     * @brief function to query status of file and return a stat structure with information about file
     *
     * @param _file
     * @return struct stat
     */
    struct stat initStat(const char *_file)
    {
        struct stat _fileStats;
        int _fd = -1;
        try
        {
            _fd = stat(_file, &_fileStats);
            if (_fd == -1)
            {
                std::cout << "\nFile does not exist!\n";
                return _fileStats;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return _fileStats;
    }
    /**
     * @brief  print file Information
     *
     * @param _fileStats
     */
    void printInfo(struct stat _fileStats)
    {
        std::cout << "\n--------File Information--------";
        std::cout << "\nFile st_uid : " << _fileStats.st_uid;
        std::cout << "\nFile st_gid : " << _fileStats.st_gid;
        std::cout << "\nFile st_blksize : " << _fileStats.st_blksize;
        std::cout << "\nFile st_blocks : " << _fileStats.st_blocks;
        std::cout << "\nFile st_size : " << _fileStats.st_size;
        std::cout << "\nFile st_nlink : " << (std::size_t)_fileStats.st_nlink;
        std::cout << "\n\n--------File Permissions for user--------";
        std::cout << (_fileStats.st_mode & S_IRUSR) ? "r" : "-";
        std::cout << (_fileStats.st_mode & S_IWUSR) ? "w" : "-";
        std::cout << (_fileStats.st_mode & S_IXUSR) ? "x" : "-";
        std::cout << "\n\n--------File Permissions for group--------";
        std::cout << (_fileStats.st_mode & S_IRGRP) ? "r" : "-";
        std::cout << (_fileStats.st_mode & S_IWGRP) ? "w" : "-";
        std::cout << (_fileStats.st_mode & S_IXGRP) ? "x" : "-";
        std::cout << "\n\n--------File Permissions for others--------";
        std::cout << (_fileStats.st_mode & S_IROTH) ? "r" : "-";
        std::cout << (_fileStats.st_mode & S_IWOTH) ? "w" : "-";
        std::cout << (_fileStats.st_mode & S_IXOTH) ? "x" : "-";
    }
} // namespace utils