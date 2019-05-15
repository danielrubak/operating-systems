CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = shm sem

all: $(TARGETS)

shm: shm.c
	$(CC) $(CFLAGS) shm.c -o shm

sem: sem.c
	$(CC) $(CFLAGS) sem.c -o sem

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS)