all: a_fileCache b_fileRead readBlock

clean:
	rm -f a_fileCache b_fileRead readBlock

a_fileCache: a_fileCache.c
	gcc -o a_fileCache a_fileCache.c -Wall

b_fileRead: b_fileRead.c
	gcc -o b_fileRead b_fileRead.c -Wall

readBlock: readBlock.c
	gcc -o readBlock readBlock.c -Wall