CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = listener talker

all: $(TARGETS)

# Single client connection
listener: listener.c
	$(CC) $(CFLAGS) listener.c -o listener

talker: talker.c
	$(CC) $(CFLAGS) talker.c -o talker

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS)
