#include<iostream>
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 20
using namespace std;
inline volatile uint64_t RDTSC() {
   register uint64_t TSC asm("eax");
   register uint64_t EDX asm("edx");
   asm volatile (".byte 15, 49" : : : "eax", "edx");
   return (EDX<<32) + TSC;
};

void empty_soul0(void);
void empty_soul1(int a);
void empty_soul2(int a, int b);
void empty_soul3(int a, int b, int c);
void empty_soul4(int a, int b, int c, int d);
void empty_soul5(int a, int b, int c, int d, int e);
void empty_soul6(int a, int b, int c, int d, int e, int f);
void empty_soul7(int a, int b, int c, int d, int e, int f, int g);

// 

void *PrintHello(void *threadid) {
	long tid = 0;
	pthread_exit(NULL);
}

int main(void) {
	uint64_t lowest = 158888888888;
	
	for(int j = 1; j < 1000; j++){
		uint64_t start = RDTSC();
		pthread_t threads[NUM_THREADS];
   		int rc;
   		int i;



   		for( i = 0; i < NUM_THREADS; i++ ) {
      		rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   //pthread_exit(NULL);


		
		uint64_t end = RDTSC();
		if ((end - start) < lowest){
			lowest = (end - start);
		}
	}
	cout << "Per for RDTSC " << (lowest/20.0) - 3<< "\n";
	return 0;
}


void empty_soul0(void){
	;
}

void empty_soul1(int a){;}
void empty_soul2(int a, int b){;}
void empty_soul3(int a, int b, int c){;}
void empty_soul4(int a, int b, int c, int d){;}
void empty_soul5(int a, int b, int c, int d, int e){;}
void empty_soul6(int a, int b, int c, int d, int e, int f){;}
void empty_soul7(int a, int b, int c, int d, int e, int f, int g){;}