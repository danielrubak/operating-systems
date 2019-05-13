#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  pid_t pid;
  pid = fork();

  if (pid < 0)
    exit(EXIT_FAILURE);

  if (pid > 0) {
    // parent process
    exit(EXIT_SUCCESS);
  }

  if (pid == 0) {
    // child process
    umask(0);

    // set session id for child
    pid_t sid = setsid();
    if (sid == -1) {
      fprintf(stderr, "Setsid failed.\n");
      return EXIT_FAILURE;
    }

    printf("Child details:  pid=%d ppid=%d sid=%d\n", getpid(), getppid(), sid);

    // closing standard file descriptors
    close(0);
    close(1);
    close(2);

    // random number for every 5 seconds
    system("echo >lotto_results");
    for (int i = 0; i < 10; ++i) {
      system("shuf -i1-49 -n 6 >> lotto_results");
      system("echo >>lotto_results");
      sleep(5);
    }
  }

  return 0;
}
