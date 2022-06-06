# os-fsop FileSystem operations

command line based program for demonstration of filesystem system calls.

# Building

- # Prerequisites

  - GNU c++ compiler(g++) version 9.0 or newer with support for c++20

- # Compilation
  g++ -o fsop ../fsop/main.cpp

# Execution & Usage

- For execution, use either the executable file provided with the program or compile one for your target system.
- if no value is given to optional arguments a default value will be used.

  - \_oflag - { -rd/wr/rdwr}, defualt rd
  - \_permissions - { r-read, w-write, x-execute, ' - ' deny permission }, default read, write and execute for all (ugo)
  - \_offset - default 0

- # Usage

  ```bash

  ./fsop or ./fsop --help
  ./fsop [-create] [-unp]
  ./fsop [-create] [-np/rf] [../filename.extension]  [optional_permissions]
  ./fsop [-info] [-np/rf] [../filename.extension]
  ./fsop [-open] [-rf] [../filename.extension] [optional_oflag]
  ./fsop [-read] [-np/rf] [../filename.extension] [_bytecount] [optional_offset]
  ./fsop [-write] [-np/rf] [..filename.extension] [optional_offset]

  ```

# System Call(s) used

| Task | System call(s) used |
| Create new file/pipe | `creat` , `mknod` |
| Access existing file/pipe | `open` ,`read`, `write`, `lseek`, `close`,`stat`|
| Advanced system calls| `pipe`|

# Examples

- Create a new regular file, named as `file.txt` (blank file) with read, write and execute permissions for user and read and write permissions for group and others:

```bash
    ./fsop -create -rf file.txt rdxrw-rw-
```

- Open a named pipe, named as `mypipe` for reading:

```bash
    ./fsop -read -np mypipe
```

# About

- Created by : Kashish (kd372744@gmail.com)

# Reference

- [The Design of Unix Operating System, Maurice J.Bach](https://www.pdfdrive.com/the-design-of-the-unix-operating-system-maurice-bach-e25830714.html)
