#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>


int blockSize = 4096;
int mbSize = 1048576;
int blocksPerMB = 256;

int randomNumber(int max) {
  return rand() % max;
}


void sequentialRead(char *filename, int mbToRead) {
  struct timeval start, end;
  int bufferSize = mbSize;
  char *buffer;

  // bypass file cache with O_DIRECT
  // int fd = open(filename, O_RDONLY | O_DIRECT);
  int fd = open(filename, O_RDONLY);
  posix_memalign((void*)&buffer, mbSize, mbSize);

  gettimeofday(&start, NULL);
  for (int i = 0; i < mbToRead; i++) {
    int sizeRead = read(fd, buffer, bufferSize);
    if (sizeRead < bufferSize) {
      printf("read %d bytes on i = %d\n", sizeRead, i);
      break;
    }
  }
  gettimeofday(&end, NULL);
  long time_usec = end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec;
  double perBlockTime = (double) time_usec / (mbToRead * blocksPerMB);
  printf("size of file: %d megabytes\nper-block-time: %f microseconds\n", mbToRead, perBlockTime);
}

void randomRead(char *filename, int mbToRead) {
  struct timeval start, end;
  int bufferSize = mbSize;
  char *buffer;
  off_t offset;

  // bypass file cache with O_DIRECT
  // int fd = open(filename, O_RDONLY | O_DIRECT);
  int fd = open(filename, O_RDONLY);
  posix_memalign((void*)&buffer, mbSize, mbSize);

  gettimeofday(&start, NULL);
  for (int i = 0; i < mbToRead; i++) {
    offset = (off_t) randomNumber(mbToRead);
    lseek(fd, offset * mbSize, SEEK_SET);
    int sizeRead = read(fd, buffer, bufferSize);
    if (sizeRead < bufferSize) {
      printf("read %d bytes on i = %d\n", sizeRead, i);
      break;
    }
  }
  gettimeofday(&end, NULL);
  long time_usec = end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec;
  double perBlockTime = (double) time_usec / (mbToRead * blocksPerMB);
  printf("size of file: %d megabytes\nper-block-time: %f microseconds\n", mbToRead, perBlockTime);
}


int main(int argc, char *argv[]) {
  int mbToRead = atoi(argv[2]);
  sequentialRead(argv[1], mbToRead);
  randomRead(argv[1], mbToRead);
  return 0;
}