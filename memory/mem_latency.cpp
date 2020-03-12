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
#define STRIDE_WIDTH 16
using namespace std;

double lantency_test(int memSize, ofstream &output);
double cacheAccessTime(int size, int strideLength);

inline volatile uint64_t RDTSC() {
   register uint64_t TSC asm("eax");
   register uint64_t EDX asm("edx");
   asm volatile (".byte 15, 49" : : : "eax", "edx");
   return (EDX<<32) + TSC;
};


// the output format would be, size of memory in uses (KB) and average access time in cycle count.
// i.e., 128 22
double latency_test(int memSize, ofstream &output);

int main(int argc, char const *argv[])
{
	ofstream myfile;
	myfile.open("Log_01");
	if (not myfile.is_open()){
		cout << "Failed to create/write to log file" << endl;
		return -1;
	}
	// This is the size array that will be used for cache line testing, unit is KB,
	// more details in lantency_test function. Note 2^20 KB = 1GB which should be 
	// larger than any given size of cache except for main RAM.
	vector<int> size_array;
	size_array.push_back(1);
	for(int i = 1; i <= 20; i++){
		size_array.push_back(1<<i);
	}

	cout << "L1 cache latency" << cacheAccessTime(24, 16) << endl;
	cout << "L2 cache latency" << cacheAccessTime(128, 64) << endl;
	cout << "L3 cache latency" << cacheAccessTime(1024*6, 128) << endl;
	cout << "dram cache latency" << cacheAccessTime(1024*512, 16) << endl;

	//latency_test(size_array[19], myfile);
	myfile.close();
	return 0;
}

double cacheAccessTime(int size, int strideLength)
{
    int* A = (int *)malloc(size * 1024 / 4 * sizeof(int));
    int num, length;
    length = strideLength / 4;   
    num = size * 1024 / 4;
    cout << num << endl;
    int index = 0;
    A[0] = 0;
    for (int i = 0; i < num; i++) {
        
        if (index >= num) {
            index %= num;
        }
        A[i] = index;
        index = i + length;
    }
	cout << num << endl;
    int x = 0;
    int64_t start;
    int64_t end;
    int64_t total_time = 0;
    int count = COUNT;

    start = RDTSC();
    for (int i = 0; i < num; i++) {
        x = A[x];
    }
    end = RDTSC();
    total_time = end - start;
    cout << num << endl;
    double ans = total_time / (num * 1.0);
    free(A);
    return ans;
}