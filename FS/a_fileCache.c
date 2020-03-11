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

int main(int argc, char *argv[]) {
  struct timeval start, end;
  int bufferSize = mbSize;
  char *buffer = (char *) malloc(bufferSize);

  int fd = open(argv[1], O_RDONLY);
  int mbToRead = atoi(argv[2]);

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
  printf("total time: %ld microseconds\n", time_usec);
  printf("per-block-time: %f microseconds\n", perBlockTime);
  return 0;
}