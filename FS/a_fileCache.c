// #include <sys/types.h>
// #include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>


int blockSize = 4096;
int mbSize = 1048576;
int blocksPerMB = 256;


double read_file(int mbToRead){
  struct timeval start, end;
  int bufferSize = blockSize;
  char *buffer;

  int fd = open("1", __O_DIRECT);
  posix_memalign((void*)&buffer, blockSize, blockSize);
  for (int i = 0; i < mbToRead; i++) {
    read(fd, buffer, bufferSize);
  }
  lseek(fd, 0, SEEK_SET);

  gettimeofday(&start, NULL);
  for (int i = 0; i < mbToRead; i++) {
    int sizeRead = read(fd, buffer, bufferSize);
    if (sizeRead < mbSize) {
      printf("read %d bytes on i = %d\n", sizeRead, i);
      break;
    }
  }
  gettimeofday(&end, NULL);
  free(buffer);
  long time_usec = end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec;
  double perBlockTime = (double) time_usec / (mbToRead * blocksPerMB);
  // printf("total time: %ld microseconds\n", time_usec);
  printf("%d MB : per-block-time: %f microseconds\n", mbToRead, perBlockTime);
  return perBlockTime;
}

int main(int argc, char *argv[]) {
  for(int i = 1; i<=1024*16; i*= 2){
    double perBT = read_file(i);
  }
}