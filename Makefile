CFLAGS = -std=c99 -Wall -pedantic  
CC =gcc

all: test2 

test2: array.o test2.o 
	$(CC) $(CFLAGS)  array.o -o test2.o -o test2

array.o: array.c
	$(CC) $(CFLAGS) -c array.c -o array.o

test2.o: test2.c
	$(CC) $(CFLAGS) -c test2.c -o test2.o
	
clean: 
	rm -i  array.o test6.o  test5.o test4.o test3.o test2.o test1.o test6 test5 test4 test3 test2 test1 
	




























