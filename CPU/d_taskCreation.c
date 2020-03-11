#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h> // threads

// access to rdtsc
#include <x86intrin.h>

int NUM_LOOPS = 10000;

u_int64_t rdtsc() {
  return __rdtsc();
}

void measureProcCreate() {
  u_int64_t start, end;

  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    int rc = fork();
    if (rc == 0) {
      exit(0);
    }
  }
  end = rdtsc();
  printf("Process Creation: %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void *thread_function() {
  return NULL;
}

void measureThreadCreate() {
  u_int64_t start, end;
  pthread_t thread;

  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    pthread_create(&thread, NULL, thread_function, NULL);
    pthread_join(thread, NULL);
  }
  end = rdtsc();

  printf("Thread Creation: %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

int main(int argc, char *argv[]) {
  measureProcCreate();
  measureThreadCreate();
  return 0;
}