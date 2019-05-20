CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = server client server2 client2 server3 client3

all: $(TARGETS)

# Single client connection
server: server.c
	$(CC) $(CFLAGS) server.c -o server

client: client.c
	$(CC) $(CFLAGS) client.c -o client

# Multiple clients connection
server2: server2.c
	$(CC) $(CFLAGS) server2.c -o server2

client2: client2.c
	$(CC) $(CFLAGS) client2.c -o client2

# Both side communication between server and multiple client
server3: server3.c
	$(CC) $(CFLAGS) server3.c -o server3

client3: client3.c
	$(CC) $(CFLAGS) client3.c -o client3

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS)
