import os

MB_16 = 1024*1024*16


for i in range(30):
  with open('./contention/foo_{}'.format(i), 'wb') as f:
    f.write(os.urandom(MB_16))