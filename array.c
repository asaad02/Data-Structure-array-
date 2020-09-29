

struct Performance *newPerformance(){
    // allocate memory for a performance struct 

    struct Performance *newPerformance = (struct Performance *) malloc(sizeof(struct Performance));

    //print an error message to the standard error stream and exit if the malloc function fails.
    if(newPerformance == Null){
        puts("malloc error");
        exit(1);
    }

    // set zero to reads, writes, malloc , free 

    newPerformance -> reads = 0;
    newPerformance -> writes = 0;
    newPerformance -> mallocs = 0;
    newPerformance -> frees = 0;

    // return the address of the new function
    return newPerformance;
}

struct Array *newArray(struct Performance *performance, unsigned int width, unsigned int capacity ){

    // allocate sufficient memory for an Array structur
    struct Array *newArray = (struct Array *) malloc(sizeof(struct Array));

    //print an error message to the standard error stream and exit if the malloc function fails.
    if(newArray == Null){
        puts("malloc error");
        exit(1);
    }

    //set Width and capicity to the value provide by function Agreement.
    newArray -> width = width ;
    newArray -> capacity = capacity;

    // set nel to zero 
    newArray -> nel = 0 ;

    // allocate width and capacity memory string into the address of data. 
    newArray -> data = malloc(width * capacity );

     if(newArray -> data == Null){
        puts("malloc error in the malloc for data");
        exit(1);
    }

    // increment the mallocs
    performance -> mallocs++;

    // return pointer a pointer of the allocated array structure.
    newArray *ptr ;
    *ptr = newArray;
    return ptr;
}