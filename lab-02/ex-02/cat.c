/*
Basic implementation of cat command. There is possibility to read text from
file/files or from standard input.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 512

static char *read_line();

int main(int argc, char **argv) {
  if (argc > 1) {
    // reading from file/files
    for (int i = 1; i < argc; i++) {
      FILE *f = fopen(argv[i], "r");
      if (f == NULL) {
        fprintf(stderr, "%s: %s: ", argv[0], argv[i]);
        perror("");
        exit(EXIT_FAILURE);
      }

      char *line = NULL;
      size_t len = 0;
      size_t read;

      while ((read = getline(&line, &len, f)) != -1) {
        printf("%s", line);
      }
    }
  } else {
    // reading from stdin
    char *input;
    do {
      input = read_line(stdin);
      printf("%s\n", input);
      free(input);
    } while (strcmp(input, "\n") != 0);
  }
  return 0;
}

static char *read_line() {
  size_t capacity = BUFFSIZE, current_index = 0;
  char *buffer = malloc(capacity * sizeof(char));
  int c;

  while ((c = fgetc(stdin)) != '\n' && !feof(stdin)) {
    buffer[current_index] = c;

    // when capacity is equal to current index we need to resize buffer
    if (++current_index == capacity)
      buffer = realloc(buffer, (capacity *= 2) * sizeof(char));
  }

  buffer = realloc(buffer, (current_index + 1) * sizeof(char));
  buffer[current_index] = '\0';
  return buffer;
}
