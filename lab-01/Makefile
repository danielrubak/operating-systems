CC = gcc
CFLAGS = -g -pedantic -Wall
TARGETS = ex1open

all: $(TARGETS)

ex1open: ex-03/ex1open.c
	$(CC) $(CFLAGS) ex-03/ex1open.c -o ex-03/ex1open

.PHONY: clean

clean:
	$(RM) *~ */*.o */$(TARGETS)
