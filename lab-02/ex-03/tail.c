/*
The basic implementation of the "tail" command. There is only the option of
reading text from a file / files. The program should print the last 10 lines of
each file to the standard output only if the -n flag is not used. If the -n flag
is used, only n lines of each file should be printed.
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 512

void tail(FILE* file, char* file_name, int n);

int main(int argc, char** argv) {
  int file_count = 0;
  int n_flag_value = 10;

  if (argc > 1) {
    // reading from file/files
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        switch (argv[i][1]) {
          case 'n':
            n_flag_value = atoi(argv[++i]);
            printf("%d\n", n_flag_value); /**/
            break;
          case '-':
            break;
        }
      }
    }

    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        FILE* f = fopen(argv[i], "r");
        if (f == NULL) {
          fprintf(stderr, "./: open: %s: %s\n", argv[0], strerror(errno));
          continue;
        }
        /*printf("OPTIONS: file = '%s', n = %d\n", argv[i], n_flag_value); /**/
        tail(f, argv[i], n_flag_value);
        printf("\n");
        fclose(f);
      }
    }
  }

  return 0;
}

void tail(FILE* file, char* file_name, int n) {
  int nl_count = 0, c;  // To count new line characters
  long pos;
  char str[2 * BUFFSIZE];

  if (!fseek(file, 0, SEEK_END)) {
    pos = ftell(file);
    fseek(file, 0, SEEK_END);

    while (pos > 0) {
      c = fgetc(file);
      if (c != EOF) {
        /*printf("Position in file: %ld, Stored value: ASCII -> %d, CHAR ->
           %c\n", pos, c, c); /**/
        if (c == '\n' && ++nl_count == n) {
          /*printf("Position in file: %ld, Stored value: NL\n", pos); /**/
          break;
        }
      } else {
        /*printf("Position in file: %ld, Stored value: EOF\n", pos); /**/
      }
      fseek(file, --pos, SEEK_SET);
    }

  } else {
    // error handling
  }

  // print last n lines
  printf("==> %s <==\n", file_name);
  while (fgets(str, sizeof(str), file)) printf("%s", str);
}
