#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>

// access to rdtsc
//#include <x86intrin.h>

int NUM_LOOPS = 100000000;

static inline volatile u_int64_t rdtsc() {
   register u_int64_t TSC asm("eax");
   register u_int64_t EDX asm("edx");
   asm volatile (".byte 15, 49" : : : "eax", "edx");
   return (EDX<<32) + TSC;
};


void measureForLoop() {
  u_int64_t start, end;

  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    //printf("For loop Overhead: %d cycles\n", 22);
    ;
  }
  end = rdtsc();
  printf("For loop Overhead: %f cycles\n", (double)(end-start) / NUM_LOOPS);
}

void measureReading() {
  u_int64_t start, end;

  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    rdtsc();
  }
  end = rdtsc();
  printf("Reading Overhead: %f cycles\n", (double)(end-start) / NUM_LOOPS);
}

int main(int argc, char *argv[]) {
  measureForLoop();
  measureReading();
  return 0;
}