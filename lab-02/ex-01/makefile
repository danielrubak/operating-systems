# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#	-ansi		this is equivalent to -std=c90, turns off certain features of GCC that are incompatible with ISO C90
#	-g    		adds debugging information to the executable file
#	-Wall		turns on most, but not all, compiler warnings
#	-pedantic	used in conjunction with -ansi, this tells the compiler to be adhere strictly to the ANSI standard, rejecting
#				any	code which is not compliant.
#	-O			set the compiler optimization level, available options: -O(0-3), -Os, -Ofast
CFLAGS = -g -pedantic -Wall

# define any libraries to link into executable:
LIBS =

# define the C source files
SRCS := $(shell find . -name '*.c')

# define the C object files
OBJS = $(SRCS:.c=.o)

# the build target executable:
TARGET = copy1

# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
default: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) $(TARGET) *.o *~