#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t pid, sid;
  pid = fork();
  // get session id from parent process
  sid = getsid(0);

  if (pid < 0)
    exit(EXIT_FAILURE);
  if (pid > 0) {
    printf("Parent: pid=%d ppid=%d sid=%d\n", getpid(), getppid(), sid);
  }
  if (pid == 0) {
    // set new session id fro child process
    pid_t child_sid = setsid();

    // get session id using ps
    // ps -s

    printf("Child:  pid=%d ppid=%d sid=%d\n", getpid(), getppid(), child_sid);
  }

  exit(EXIT_SUCCESS);
}
