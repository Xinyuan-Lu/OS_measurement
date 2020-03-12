#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sched.h>

// access to rdtsc
#include <x86intrin.h>

int NUM_LOOPS = 10000;

u_int64_t rdtsc() {
  return __rdtsc();
}

void measureContextSwitch() {
  // set task affinity to single core
  // cpu_set_t cpu_set;
  // CPU_ZERO(&cpu_set);
  // CPU_SET(0, &cpu_set);
  u_int64_t start, end;

  int pipefd1[2], pipefd2[2];

  // setup two pipes
  if (pipe(pipefd1) == -1) {
    fprintf(stderr, "pipe failed");
    exit(1);
  }

  if (pipe(pipefd2) == -1) {
    fprintf(stderr, "pipe failed");
    exit(1);
  }

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork");
    exit(1);
  } else if (rc == 0) {
    // if (sched_setaffinity(0, sizeof(cpu_set_t), &cpu_set) == -1) {
    //   fprintf(stderr, "setaffinity failed");
    //   exit(1);
    // }
  int buffer;
  for (int i = 0; i < NUM_LOOPS; i++) {
      read(pipefd1[0], &i, 4);
      write(pipefd2[1], &buffer, 4);
    }
    
  } else {
    // if (sched_setaffinity(0, sizeof(cpu_set_t), &cpu_set) == -1) {
    //   fprintf(stderr, "setaffinity failed");
    //   exit(1);
    // }

    start = rdtsc();
    int buffer_2;
    for (int i = 0; i < NUM_LOOPS; i++) {
      write(pipefd1[1], &i, 4);
      read(pipefd2[0], &buffer_2, 4);
    }
    end = rdtsc();

    printf("Context Switch: %f cycles\n", (double) (end - start) / (NUM_LOOPS * 2)-1700*2);
  }
}

int main(int argc, char *argv[]) {
  measureContextSwitch();
  return 0;
}