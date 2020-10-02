CFLAGS = -std=c99 -Wall -pedantic  
CC =gcc

all: test6

test6: test6.o array.o
	$(CC) test6.o array.o -o $@


array.o: array.c
	$(CC) $(CFLAGS) -c array.c -o $@
	
run:
	test6
	
clean: 
	rm -i  array.o test6.o  test5.o test4.o test3.o test2.o test1.o test6 test5 test4 test3 test2 test1 
	




























