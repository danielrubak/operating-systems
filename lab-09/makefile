CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = morse sessions deamon

all: $(TARGETS)

morse: morse_temp.c
	$(CC) $(CFLAGS) morse_temp.c -o morse

sessions: sessions.c
	$(CC) $(CFLAGS) sessions.c -o sessions

deamon: deamon.c
	$(CC) $(CFLAGS) deamon.c -o deamon

.PHONY: clean

clean:
	$(RM) *~ *.o $(TARGETS) lotto_results
