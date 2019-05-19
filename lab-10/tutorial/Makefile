CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = server server2 client

all: $(TARGETS)

server: server.c
	$(CC) $(CFLAGS) server.c -o server

server2: server2.c
	$(CC) $(CFLAGS) server2.c -o server2

client: client.c
	$(CC) $(CFLAGS) client.c -o client

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS) lotto_results
