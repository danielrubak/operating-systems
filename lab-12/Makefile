CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = hostinfo gethostbyname-demo showip

all: $(TARGETS)

hostinfo: hostinfo.c
	$(CC) $(CFLAGS) hostinfo.c -o hostinfo

gethostbyname-demo: gethostbyname-demo.c
	$(CC) $(CFLAGS) gethostbyname-demo.c -o gethostbyname-demo

showip: showip.c
	$(CC) $(CFLAGS) showip.c -o showip

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS)
