/* Example of how to run a command such as:
who | cut -d' ' -f1 | sort | uniq -c | sort -r
using C and Unix. */

// TO-DO:
// Code refactoring
// More flexible commands execution

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int pipefd_1[2], pipefd_2[2], pipefd_3[2], pipefd_4[2], status;

  pid_t cpid;

  pipe(pipefd_1);
  pipe(pipefd_2);
  pipe(pipefd_3);
  pipe(pipefd_4);

  cpid = fork();
  if (cpid == 0) {
    // move output to pipe
    dup2(pipefd_1[1], STDOUT_FILENO);
    execlp("who", "who", (char*)NULL);
  }

  cpid = fork();
  if (cpid == 0) {
    // close unused write end
    close(pipefd_1[1]);
    // get input from pipe
    dup2(pipefd_1[0], STDIN_FILENO);
    // move output to next pipe
    dup2(pipefd_2[1], STDOUT_FILENO);
    execlp("cut", "cut", "-d", " ", "-f1", (char*)NULL);
  }

  // close pipe so EOF can work
  close(pipefd_1[0]);
  // it will not terminate because parent have write end open
  close(pipefd_1[1]);

  cpid = fork();
  if (cpid == 0) {
    // close unused write end
    close(pipefd_2[1]);
    // get input from pipe
    dup2(pipefd_2[0], STDIN_FILENO);
    // move output to next pipe
    dup2(pipefd_3[1], STDOUT_FILENO);
    execlp("sort", "sort", (char*)NULL);
  }

  // close pipe so EOF can work
  close(pipefd_2[0]);
  // it will not terminate because parent have write end open
  close(pipefd_2[1]);

  cpid = fork();
  if (cpid == 0) {
    // close unused write end
    close(pipefd_3[1]);
    // get input from pipe
    dup2(pipefd_3[0], STDIN_FILENO);
    // move output to next pipe
    dup2(pipefd_4[1], STDOUT_FILENO);
    execlp("uniq", "uniq", "-c", (char*)NULL);
  }

  // close pipe so EOF can work
  close(pipefd_3[0]);
  // it will not terminate because parent have write end open
  close(pipefd_3[1]);

  cpid = fork();
  if (cpid == 0) {
    // close unused write end
    close(pipefd_4[1]);
    // get input from pipe
    dup2(pipefd_4[0], STDIN_FILENO);

    execlp("sort", "sort", "-r", (char*)NULL);
  }

  // close pipe so EOF can work
  close(pipefd_4[0]);
  // it will not terminate because parent have write end open
  close(pipefd_4[1]);

  waitpid(-1, &status, 0);
  waitpid(-1, &status, 0);
  waitpid(-1, &status, 0);
  waitpid(-1, &status, 0);

  return 0;
}