# Systemy operacyjne

The notes were prepared on the basis of Marc Rochkind's book "Advanced UNIX Programming (2nd edition)". May contain copied content of this book or its loose interpretation.

## Introduction
Kinds of UNIX files:
* Regular files
* Directories
* Symbolic links
* Special files
* Named pipes (FIFOs)
* Sockets

**REGULAR FILES**
Contains bytes of data organized into a linear array and are stored on disk. Reads/writes start at byte location specified by the file offset which can be any value (even beyond the end of the file).
It is impossible to insert/delete bytes into/from middle of a file. Two or more process can read and write at the same time but the result is unpredictable. To maintain order there are file-locking facilities and semaphores. Files don’t have names but i-numbers. This is an index into an array of i-nodes, kept at the front of each region of disk that contains a UNIX file system. I-node include following information:
- type of file,
- owner user and group ID,
- permissions,
- size in bytes,
- time of last access, last modification and last status change,
- pointer to file content.

**DIRECTORIES AND SYMBOLIC LINKS**
Directories allow refer to file by name so almost always is are used to access to files. Each directory consists table with name and i-number. This pair is called a link. When the UNIX kernel is told to access a file by name, it automatically looks in a directory to find the i-number. Kernel keeps track of the i-number of current directory for each process (it's called relative path). An absolute path begins with a '/'.

It is possible that two or more links are refer to the same i-number (It means that file may have more than one name).
