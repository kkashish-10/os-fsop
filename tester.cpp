#include <bits/stdc++.h>
#include <fcntl.h>
using namespace std;
int main(int argc, char **argv)
{
    std::string _perm = "rwxrwxrwx";
    auto _mode = 0000;
    if (_perm[0] == 'r')
        _mode |= 0400;
    if (_perm[1] == 'w')
        _mode |= 0200;
    if (_perm[2] == 'x')
        _mode |= 0100;
    // _mode = _mode << 3;
    if (_perm[3] == 'r')
        _mode |= (0400 >> 3);
    if (_perm[4] == 'w')
        _mode |= (0200 >> 3);
    if (_perm[5] == 'x')
        _mode |= (0100 >> 3);
    // _mode = _mode << 3;
    if (_perm[6] == 'r')
        _mode |= ((0400 >> 3) >> 3);
    if (_perm[7] == 'w')
        _mode |= ((0200 >> 3) >> 3);
    if (_perm[8] == 'x')
        _mode |= ((0100 >> 3) >> 3);
    std::cout << std::oct << _mode;
    std::cout << (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
    creat("/home/ddos/Desktop/xyza.txt",(mode_t)_mode);
    return 1;
}