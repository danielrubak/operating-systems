CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = backward tail

all: $(TARGETS)

backward: backward.c
	$(CC) $(CFLAGS) backward.c -o backward

tail: tail.c
	$(CC) $(CFLAGS) tail.c -o tail

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS)
