CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = server client

all: $(TARGETS)

server: server.c
	$(CC) $(CFLAGS) server.c -o server

client: client.c
	$(CC) $(CFLAGS) client.c -o client

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS) lotto_results
