# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# command to remove a file, default: rm -f
RM = rm -vf

# compiler flags:
#	-ansi		this is equivalent to -std=c90, turns off certain features of GCC that are incompatible with ISO C90
#	-g    		adds debugging information to the executable file
#	-Wall		turns on most, but not all, compiler warnings
#	-pedantic	used in conjunction with -ansi, this tells the compiler to be adhere strictly to the ANSI standard, rejecting
#				any	code which is not compliant.
#	-O			set the compiler optimization level, available options: -O(0-3), -Os, -Ofast
CFLAGS = -Wall -g -pedantic -pthread

# extra flags to give to the C preprocessor and programs that use it
CPPFLAGS= -I.

# define any libraries to link into executable:
LIBS =

# define the C source files
SRCS= $(wildcard *.c)

# define the C object files
OBJS= $(patsubst %.c, %.o, $(SRCS))

# define the executable files
EXECS= $(patsubst %.c, %, $(SRCS))

.PHONY: all clean

all: $(EXECS)

clean:
	$(RM) $(OBJS) $(EXECS) *~