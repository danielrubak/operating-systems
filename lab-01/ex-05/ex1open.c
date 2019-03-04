#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "t.h"

#define BUFSIZE 1024

int main (int argc, char **argv) {
    int f1, result, c;
    char b[BUFSIZE], *n1;

    c = 10;
    n1 = argv[1];

    timestart();

    f1 = open (n1, O_RDONLY);
    if (f1 == -1) {
        perror("Error during 'open' function execution");
        exit(EXIT_FAILURE);
    }

    result = read (f1, b, c);
    if (result == -1) {
        perror("Error during 'read' function execution");
        exit(EXIT_FAILURE);
    }

    printf("%s: Przeczytano %d znakow z pliku %s: \"%s\"\n",
	   argv[0], c, n1, b);
    close(f1);

    timestop("End of execution time calculating");

    return(0);
}
