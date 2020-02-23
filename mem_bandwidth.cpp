#include<iostream>
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 20
#include <sys/time.h>
using namespace std;


// According to the documentation, inline keyword reduce to need for adding function to stack
// and volatile force the program to read from memory, instead if reading it from cache.
inline volatile uint64_t RDTSC() {
   register uint64_t TSC asm("eax");
   register uint64_t EDX asm("edx");
   asm volatile (".byte 15, 49" : : : "eax", "edx");
   return (EDX<<32) + TSC;
};



// So, the idea is to valloc some memory, i.e., 256 int, and read from it. we can use 1, for loop unroll
// Actually, we shouldn't use the RDTSC() as a measure to read time. Instead, we should use in system time.
int main(int ac, char **av){
	register int loops_needed_for_1GB = 1024*1024;
	register int* intBuffer = (int*) valloc(256*sizeof(int)*loops_needed_for_1GB); // 1 kb * 1024 * 1024 = 1GB

	//Important. 
	for(int i = 0; i < 256*loops_needed_for_1GB; i++){
		intBuffer[i] = 0;
	}
	register int sum = 0;
	
	struct timeval start_time_s, end_time_s;
	gettimeofday(&start_time_s, 0);
	//since we have prefetch overhead, and the cache line is 64 bytes, then we only needs to read every 64 bytes / 4 bytes.

	uint64_t start_time = RDTSC();

	while(loops_needed_for_1GB --){
		sum += intBuffer[0] + intBuffer[16] + intBuffer[32] + intBuffer[48] + intBuffer[64] + intBuffer[80] + intBuffer[96] + intBuffer[112] + intBuffer[128] + \
		intBuffer[144] + intBuffer[160] + intBuffer[176] + intBuffer[192] + intBuffer[208] + intBuffer[224] + intBuffer[240];
		intBuffer += 256;
	}
	uint64_t end_time = RDTSC();

	gettimeofday(&end_time_s, 0);
	printf("%.2f\n", (end_time_s.tv_usec - start_time_s.tv_usec)/1000000.0);
	// Need to deduct the forloop overhead. 
	printf("%ld, %ld %d\n", (end_time-start_time), (end_time-start_time-3*1024*1024), 3*1024*1024);
	printf("%.2f G\n", 1/((end_time-start_time-3*1024*1024)/(1000000000*2.2)));
	if(sum != 0){printf("(Something wrong)\n");}
	return 0;
}

