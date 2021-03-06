/*
 * copy1.c
 *
 * based on:
 *
 * Miscellaneous examples for Chap. 2
 * AUP2, Chap. 2
 *
 * modified by WTA
 */

/*[copy-with-bug]*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFSIZE 512

void copy(char *from, char *to) {
  int fromfd = -1, tofd = -1;
  ssize_t nread;
  char buf[BUFSIZE];

  fromfd = open(from, O_RDONLY);
  if (fromfd == -1) {
    if (errno == EACCES) {
      fprintf(stderr, "Open '%s' file: ", from);
      perror("");
      exit(EXIT_FAILURE);
    } else if (errno == ENOENT) {
      fprintf(stderr, "Open '%s' file: ", from);
      perror("");
      exit(EXIT_FAILURE);
    } else {
      perror("Unhandled error");
      exit(EXIT_FAILURE);
    }
  }

  tofd = open(to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  while ((nread = read(fromfd, buf, sizeof(buf))) > 0) {
    if (write(tofd, buf, nread) == -1) {
      perror("Unhandled error, write");
      exit(EXIT_FAILURE);
    }
  }

  close(fromfd);
  close(tofd);

  return;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s from_pathname to_pathname\n", argv[0]);
    return 1;
  }
  copy(argv[1], argv[2]);
  return 0;
}
