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

both-targets:
	${MAKE} backward
	${MAKE} tail

backward: $(OBJS_BACKWARD)
	$(CC) $(CFLAGS) -o backward backward.c $(LIBS)

tail: $(OBJS_TAIL)
	$(CC) $(CFLAGS) -o tail tail.c $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) backward tail *.o *~