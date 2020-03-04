#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// access to rdtsc
#include <x86intrin.h>

int NUM_LOOPS = 10000;

uint64_t rdtsc() {
  return __rdtsc();
}

void procedure0() {;}
void procedure1(int a) {;}
void procedure2(int a, int b) {;}
void procedure3(int a, int b, int c) {;}
void procedure4(int a, int b, int c, int d) {;}
void procedure5(int a, int b, int c, int d, int e) {;}
void procedure6(int a, int b, int c, int d, int e, int f) {;}
void procedure7(int a, int b, int c, int d, int e, int f, int g) {;}

void measureProc0() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure0();
  }
  end = rdtsc();
  printf("Procedure Call (0 args): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProc1() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure1(0);
  }
  end = rdtsc();
  printf("Procedure Call (1 arg): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProc2() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure2(0,0);
  }
  end = rdtsc();
  printf("Procedure Call (2 args): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProc3() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure3(0,0,0);
  }
  end = rdtsc();
  printf("Procedure Call (3 args): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProc4() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure4(0,0,0,0);
  }
  end = rdtsc();
  printf("Procedure Call (4 args): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProc5() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure5(0,0,0,0,0);
  }
  end = rdtsc();
  printf("Procedure Call (5 args): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProc6() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure6(0,0,0,0,0,0);
  }
  end = rdtsc();
  printf("Procedure Call (6 args): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProc7() {
  uint64_t start, end;
  start = rdtsc();
  for (int i = 0; i < NUM_LOOPS; i++) {
    procedure7(0,0,0,0,0,0,0);
  }
  end = rdtsc();
  printf("Procedure Call (7 args): %f cycles\n", (double) (end - start) / NUM_LOOPS);
}

void measureProcCall() {
  measureProc0();
  measureProc1();
  measureProc2();
  measureProc3();
  measureProc4();
  measureProc5();
  measureProc6();
  measureProc7();
}

int main(int argc, char *argv[]) {
  measureProcCall();
  return 0;
}