#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// access to rdtsc
#include <x86intrin.h>

int NUM_LOOPS = 10000;

uint64_t rdtsc() {
  return __rdtsc();
}

void measureSysCall() {
  uint64_t start, end;
  
  int fd = open("./syscall.txt", O_CREAT|O_TRUNC, S_IRWXU);

  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    // getpid();
    // read 0 bytes instead of getpid() because of caching
    read(fd, NULL, 0);
  }
  end = rdtsc();
  printf("System Call: %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

int main(int argc, char *argv[]) {
  measureSysCall();
  return 0;
}