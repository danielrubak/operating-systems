# Operating Systems

This repository contains the source code of simple programs that I developed as part of the course "Operating Systems" at AGH University of Science and Technology.

## Table of content

* **lab-01 - Introduction to programming in C**
  * `man` command
  * basic error handling, `perror()` and `strerror()` functions
  * `open()` and `read()` functions
  * creating makefile and gcc flags
* **lab-02 - Basic file I/O operations**
  * basic operations on files, `open()`, `close()`, `read()`, `write()`
  * repositiong file offset by `lseek()`
* **lab-03 - Advanced file I/O operations**
  * get data from `stat` structure
  * processing data about files
* **lab-04 - Introduction to processes**
  * function `fork()` and `exec()`
  * own implementation of simple shell
* **lab-05 - Processes and threads**
  * creating threads via `pthread_create()` and waiting for finish `pthread_join()`
  * threads synchronization using mutexes
  * functions `pthread_mutex_lock()` and `pthread_mutex_unlock()`
  * conditional variables (functions `pthread_cond_signal()` and `pthread_cond_wait()`)
* **lab-06 - IPC (Inter-process communication), part 1**
  * communication between processes by pipes
* **lab-07 - IPC (Inter-process communication), part 2**
  * named pipes
  * communication based on System V
  * communication based on POSIX standard
* **lab-08 - IPC (Inter-process communication), part 3**
* **lab-09 - Terminal I/O**
  * sessions and process groups
  * system calls
  * own implementation of Morse alphabet
* **lab-10 - Networking and sockets, part 1**
  * introduction to sockets
  * simple client and server implementation
  * functions `socket()`, `bind()`, `listen()`, `accept()`, `connect()`
* **lab-11 - Networking and sockets, part 2**
  * connectionsless sockets
  * listener and talker implementation
* **lab-12 - Networking and sockets, part 3**
  * getting information about networks, hosts, services etc.

## Additional information

Some files contain source code from *Advanced Unix Programming, 2nd edition*, Marc J. Rochkind.
