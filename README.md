# os-fsop FileSystem operations

command line based program for demonstration of filesystem system calls.

# Execution & Usage

- For execution, use either the executable file provided with the program or compile one for your target system.

- # Usage
- if no value is given to optional arguments a default value will be used.

- _oflag -  { -rd/wr/rdwr}, defualt rd
- _permissions - { r-read, w-write, x-execute, ' - ' deny permission }, default read, write and execute for all (ugo)
- _offset - defautl 0

    ```bash

    ./fsop or ./fsop --help
    ./fsop [-create] [-unp]
    ./fsop [-create] [-np/rf] [../filename.extension]  [optional_permissions]
    ./fsop [-info] [-np/rf] [../filename.extension]
    ./fsop [-open] [-rf] [../filename.extension] [optional_oflag] 
    ./fsop [-read] [-np/rf] [../filename.extension] [_bytecount] [optional_offset]
    ./fsop [-write] [-np/rf] [..filename.extension] [optional_offset]

    ```



