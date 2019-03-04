#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
#define BUFSIZE 1024
 
int main (int argc, char **argv) {
    int f1, c;
    char b[BUFSIZE], *n1;
 
    c = 10;
    n1 = argv[1];
 
    f1 = open (n1, O_RDONLY);
    read (f1, b, c);
    printf("%s: Przeczytano %d znakow z pliku %s: \"%s\"\n",
	   argv[0], c, n1, b);
    close(f1);
 
    return(0);
}
