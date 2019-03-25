#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 10

// ----------------------------------------------------------

void *PrintHello(void *threadid);

// ----------------------------------------------------------

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc;
  intptr_t t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("In main: creating thread %ld\n", (long)t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc) {
      fprintf(stderr, "Failed to create thread #%ld - %s\n", (long)t,
              strerror(rc));
      exit(EXIT_FAILURE);
    }
  }

  for (t = 0; t < 10; ++t) {
    rc = pthread_join(threads[t], NULL);

    if (rc) {
      fprintf(stderr, "Failed to create thread #%ld - %s\n", (long)t,
              strerror(rc));
      exit(EXIT_FAILURE);
    }
  }

  printf("End of the main thread!\n");
  return 0;
}

// ----------------------------------------------------------

void *PrintHello(void *threadid) {
  long thread_id = (long)threadid;
  printf("Next boring 'Hello World!' version! It's me, thread #%ld!\n",
         thread_id);
  return threadid;
}