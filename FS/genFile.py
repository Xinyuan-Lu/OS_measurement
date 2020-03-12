import os

output_file = "1"
for i in range(2*16):
    with open(output_file, 'ab') as fout:
        fout.write(os.urandom(512*1024*1024)) # replace 1024 with size_kb if not unreasonably large
    fout.close()