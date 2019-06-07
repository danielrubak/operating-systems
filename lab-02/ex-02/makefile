CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = writeall cat

all: $(TARGETS)

writeall: writeall.c
	$(CC) $(CFLAGS) writeall.c -o writeall

cat: cat.c
	$(CC) $(CFLAGS) cat.c -o cat

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS)
