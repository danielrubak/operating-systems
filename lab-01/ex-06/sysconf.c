#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s sysconf_file_path\n", argv[0]);
    return 1;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Error during 'fopen' function execution");
    return 1;
  }

  char *line = NULL, *pattern = "_SC";
  size_t len = 0;
  ssize_t read;
  long r;

  while ((read = getline(&line, &len, f)) != -1) {
    if (strstr(line, pattern)) {
      printf("%s", line);
    }
  }

  return 0;
}
