#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>


int blockSize = 4096;
int blocksToRead = 4096; // 16MB

int main(int argc, char *argv[]) {
  struct timeval start, end;
  char *buffer;

  // int fd = open(filename, O_RDONLY | O_DIRECT);
  int fd = open(argv[1], O_RDONLY);
  posix_memalign((void*)&buffer, blockSize, blockSize);

  gettimeofday(&start, NULL);
  for (int i = 0; i < blocksToRead; i++) {
    read(fd, buffer, blockSize);
  }
  gettimeofday(&end, NULL);
  long time_usec = end.tv_sec * 1000000 + end.tv_usec - start.tv_sec * 1000000 - start.tv_usec;
  double perBlockTime = (double) time_usec / blocksToRead;
  printf("per-block-time: %f microseconds\n", perBlockTime);
  return 0;
}