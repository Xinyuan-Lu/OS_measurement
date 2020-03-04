#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// access to rdtsc
#include <x86intrin.h>

int NUM_LOOPS = 100000;

uint64_t rdtsc() {
  return __rdtsc();
}

void measureForLoop() {
  uint64_t start, end;

  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    ;
  }
  end = rdtsc();
  printf("For loop Overhead: %f cycles\n", (double)(end-start) / NUM_LOOPS);
}

void measureReading() {
  uint64_t start, end, temp;

  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    temp = rdtsc();
  }
  end = rdtsc();
  printf("Reading Overhead: %f cycles\n", (double)(end-start) / NUM_LOOPS);
}

int main(int argc, char *argv[]) {
  measureForLoop();
  measureReading();
  return 0;
}