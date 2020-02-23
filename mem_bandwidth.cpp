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
	int* record = intBuffer;
	for(int i = 0; i < 256*loops_needed_for_1GB; i++){
		intBuffer[i] = 0;
	}
	register int sum = 0;
	//since we have pre-fetch overhead, and the cache line is 64 bytes, then we only needs to read every 64 bytes / 4 bytes.

	uint64_t start_time = RDTSC();
	while(loops_needed_for_1GB --){
		sum += intBuffer[0] + intBuffer[16] + intBuffer[32] + intBuffer[48] + intBuffer[64] + intBuffer[80] + intBuffer[96] + intBuffer[112] + intBuffer[128] + \
		intBuffer[144] + intBuffer[160] + intBuffer[176] + intBuffer[192] + intBuffer[208] + intBuffer[224] + intBuffer[240];
		intBuffer += 256;
	}
	uint64_t end_time = RDTSC();
	printf("Read speed is %.2f GB/s \n", 1/((end_time-start_time-3*1024*1024)/(1000000000*2.2)));
	loops_needed_for_1GB = 1024*1024;

	intBuffer = record;
	start_time = RDTSC();
	while(loops_needed_for_1GB -- ){
		intBuffer[0] = 0;
		intBuffer[16] = 0;
		intBuffer[32] = 0;
		intBuffer[48] = 0;
		intBuffer[64] = 0;
		intBuffer[80] = 0;
		intBuffer[96] = 0;
		intBuffer[112] = 0;
		intBuffer[128] = 0;
		intBuffer[144] = 0;
		intBuffer[160] = 0;
		intBuffer[176] = 0;
		intBuffer[192] = 0;
		intBuffer[208] = 0;
		intBuffer[224] = 0;
		intBuffer[240] = 0;
		intBuffer += 256;
	}	
	end_time = RDTSC();
	printf("Write speed is %.2f GB/s \n", 1/((end_time-start_time-3*1024*1024)/(1000000000*2.2)));
	free(record);

	// Need to use sum in order to makes sure while loop exist.
	if(sum != 0){printf("(Something wrong)\n");}
	return 0;
}

