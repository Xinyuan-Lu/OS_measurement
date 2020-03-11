import os
import sys

numFiles = int(sys.argv[1])
for i in range(numFiles):
  os.system('./readBlock ./contention/foo_{}&'.format(i))