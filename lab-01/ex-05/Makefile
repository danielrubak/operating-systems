ex1open: t.o ex1open.c
	gcc -Wall -ansi -pedantic -lm t.o ex1open.c -o ex1open

t.o: t.c t.h

clean:
	rm -f *~
	rm -f *.bak
	rm -f ex1open t.o

.PHONY:
	clean