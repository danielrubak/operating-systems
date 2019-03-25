#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

// ----------------------------------------------------------

void *PrintHello(void *threadid);

// ----------------------------------------------------------

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }
  pthread_exit(NULL);

  printf("End of the main thread!\n");
  return 0;
}

// ----------------------------------------------------------

void *PrintHello(void *threadid) {
  long thread_id = (long)threadid;
  printf("Next boring 'Hello World!' version! It's me, thread #%ld!\n",
         thread_id);
  pthread_exit(NULL);
}