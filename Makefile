CFLAGS = -std=c99 -Wall -pedantic  
CC =gcc

all: test1

test1: test1.o array.o
	$(CC) test1.o array.o -o $@

test1.o: test1.c
	$(CC) $(CFLAGS) -c test1.c -o $@
	
array.o: array.c
	$(CC) $(CFLAGS) -c array.c -o $@
	
run:
	test1
	
clean: 
	rm -i  test1.o array.o test1 
	




























