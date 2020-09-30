

struct Performance *newPerformance(){
    // allocate memory for a performance struct 

    struct Performance *newPerformance = (struct Performance *) malloc(sizeof(struct Performance));

    //print an error message to the standard error stream and exit if the malloc function fails.
    if(newPerformance == NULL){
        fprintf(stderr,"%s","Memory allocation for struct has failed\n")
        exit(0);
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
    if(newArray == NULL){
        fprintf(stderr,"%s","Memory allocation for struct has failed\n")
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
        fprintf(stderr,"%s","Memory allocation for data has failed\n")
        exit(0);
    }

    // increment the mallocs
    performance -> mallocs++;

    // return pointer a pointer of the allocated array structure.
   
    return newArray;
}

void readItem( structPerformance *performance, struct Array *array, unsigned int index, void *dest ){

    // if idex greater or equal nel should print error message and exit 
    if (idex >= array -> nel)
    {
        fprintf(stderr,"%s","index is greater or equal to the number of elements of the array \n")
        exit(0);
    }
    else
    {
        //copy width bytes from memory address data  to dest
        int offsit = index * array -> width ;
        memcpy( dest, array -> data + offsit, array -> width );
        

        // increment read at performance struct 

        performance -> read++;

    }
    
}

void writeItem( struct Performance *performance, struct Array *array, unsigned int index, void *src){
    // if index exceed or equal nel or capacity 
    if (index >= array -> nel || index >= array -> capacity)
    {
         fprintf(stderr,"%s","index is greater or equal to the number of elements of the array \n")
        exit(0);
    }
    else
    {
        //copy width byts from src into array data
        int offsit = index * array -> width ;
        memcpy( array -> data, src + offsit, array -> width );

        // if index equals nel incremented by one 
        if (index == array -> nel)
        {
            array -> nel++;
        }
        // add one to the writes in performance 
         performance -> writes++;
        
    }
    
}

void contract(struct Performance *performance, struct Array *array){

    
    if (array -> nel == 0)
    {
        fprintf(stderr,"%s"," array number equals to zero  \n")
        exit(0);
    }
    else
    {
        /
    }
    
}