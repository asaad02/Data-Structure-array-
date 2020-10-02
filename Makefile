CFLAGS = -std=c99 -Wall -pedantic  
CC =gcc

all: array.o

array.o: array.c
	$(CC) $(CFLAGS) -c array.c -o $@
	
clean: 
	rm -i  array.o test6.o  test5.o test4.o test3.o test2.o test1.o test6 test5 test4 test3 test2 test1 
	




























