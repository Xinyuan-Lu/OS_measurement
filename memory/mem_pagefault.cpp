#include<iostream>
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 20
#include <sys/time.h>
// basic file operations
#include <fstream>
#include <vector>

#define ITER_TIMES 100
#define COUNT 10000
#define PAGE_SIZE 4096 
using namespace std;


inline volatile uint64_t RDTSC() {
   register uint64_t TSC asm("eax");
   register uint64_t EDX asm("edx");
   asm volatile (".byte 15, 49" : : : "eax", "edx");
   return (EDX<<32) + TSC;
};

int main(int argc, char const *argv[]){
	std::ifstream is ("1", std::ifstream::binary);
	uint64_t start_time, end_time;
	if (is) {
		auto start = is.end;
		char* buffer = (char*)valloc(1024*sizeof(char));
		start_time = RDTSC();
		for(int i = 0; i < 2000; i++){
			is.seekg (-PAGE_SIZE, start);
			is.read (buffer, 1);
			start = is.cur;
		}
		end_time = RDTSC();
	}
	cout<<"total time " << (double)(end_time - start_time)/2000.0 << endl;

}
