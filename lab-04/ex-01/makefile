CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = shell

all: $(TARGETS)

shell: shell.c
	$(CC) $(CFLAGS) shell.c funcs.c -o shell

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS)
