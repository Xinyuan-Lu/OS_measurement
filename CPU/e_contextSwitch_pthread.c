#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sched.h>
#include <pthread.h>
// access to rdtsc
#include <x86intrin.h>

int NUM_LOOPS = 10000;
int pipefd1[2], pipefd2[2];

u_int64_t rdtsc() {
  return __rdtsc();
}

void *thread_function(){
    int buffer;
    for (int i = 0; i < NUM_LOOPS; i++) {
      read(pipefd1[0], &i, 4);
      write(pipefd2[1], &buffer, 4);
    }
}

void measureContextSwitch() {

  u_int64_t start, end;

  if (pipe(pipefd1) == -1) {
    fprintf(stderr, "pipe failed");
    exit(1);
  }

  if (pipe(pipefd2) == -1) {
    fprintf(stderr, "pipe failed");
    exit(1);
  }

    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    start = rdtsc();
    int buffer;
    for (int i = 0; i < NUM_LOOPS; i++) {
      write(pipefd1[1], &i, 4);
      read(pipefd2[0], &buffer, 4);
    }
    end = rdtsc();

    printf("Context Switch: %f cycles\n", (double) (end - start) / (NUM_LOOPS * 2));
  
}

int main(int argc, char *argv[]) {
  measureContextSwitch();
  return 0;
}