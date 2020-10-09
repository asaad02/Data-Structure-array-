/**
 * @file array.c
 * @author Abdullah Saad
 * @date september 28 2020
 * @brief File containing the function definitions that operate like arrays
 **/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <string.h>


struct Performance *newPerformance(){
    // allocate memory for a performance struct 

    struct Performance *newPerformance = (struct Performance *) malloc(sizeof(struct Performance));

    //print an error message to the standard error stream and exit if the malloc function fails.
    if(newPerformance == NULL){
        fprintf(stderr,"%s","Memory allocation for struct has failed\n");
        exit(0);
    }

    // set zero to reads, writes, malloc , free 

    newPerformance -> reads = 0;
    newPerformance -> writes = 0;
    newPerformance -> mallocs = 0;
    newPerformance -> frees = 0;

    // return the address of the new function.
    return newPerformance;
}

/* This function allocate memory for the array structure and set the value provided and return new array */
struct Array *newArray(struct Performance *performance, unsigned int width, unsigned int capacity ){

    // allocate sufficient memory for an Array structur
    struct Array *newArray = (struct Array *) malloc(sizeof(struct Array));

    //print an error message to the standard error stream and exit if the malloc function fails.
    if(newArray == NULL){
        fprintf(stderr,"%s","Memory allocation for struct has failed\n");
        exit(0);
    }

    //set Width and capicity to the value provide by function Agreement.
    newArray -> width = width ;
    newArray -> capacity = capacity;

    // set nel to zero 
    newArray -> nel = 0;

    // allocate width and capacity memory string into the address of data. 
    newArray -> data = malloc(width * capacity );

     if(newArray -> data == NULL){
        fprintf(stderr,"%s","Memory allocation for data has failed\n");
        exit(0);
    }

    // increment the mallocs
    performance -> mallocs++;

    // return pointer a pointer of the allocated array structure.
   
    return newArray;
}

/* This function read the item and copy it to the des void dest*/
void readItem( struct Performance *performance, struct Array *array, unsigned int index, void *dest ){
    
    char * arryaddress = array->data;
    // if index greater or equal nel should print error message and exit 
    if (index >= array->nel)
    {
        fprintf(stderr,"%s","index is greater or equal to the number of elements of the array in read item operation \n");
        exit(0);
    }
    else
    {
        //copy width bytes from memory address data  to dest
        //int offsit = index * array-> width ;
        memcpy( dest, &arryaddress[array->width * index], array -> width );
        

        // increment read at performance struct 

        performance -> reads++;

    }
    
}

/* this function will write the from the src to the array data */
void writeItem( struct Performance *performance, struct Array *array, unsigned int index, void *src){
    
    
    char * arryaddress = array->data; 

    if (index > array-> nel || index >= array -> capacity)
    {
         fprintf(stderr,"%s","index is greater or equal to the number of elements of the array  in write item operation\n");
        exit(0);
    }
    else
    {
        //copy width byts from src into array data
        //int offsit = index * array -> width ;
        memcpy( &arryaddress[array->width * index], src  , array -> width );

        // if index equals nel incremented by one 
        // if index exceed or equal nel or capacity 
        if (index == array -> nel)
        {
            array->nel++;
        }

        // add one to the writes in performance 
         performance -> writes++;
        
    }
    
}

/* This function will print error message otherwise will decrement array nel */
void contract(struct Performance *performance, struct Array *array){

    //if array number elements equals to zero
    if (array -> nel == 0)
    {
        fprintf(stderr,"%s"," array number elements  equals to zero  \n");
        exit(0);
    }
    else
    {
        // Decrement the array -> nel by one 
        array -> nel--;
    }
    
}

/* This function  will free array data and array structer*/
void freeArray( struct Performance *performance, struct Array *array ){
    // free  the array data
    free(array->data);

    // free the array structure 
    free(array);

    //increment free by one 
    performance -> frees ++;
}

/* add elemnts to the end of the array */
void appendItem( struct Performance *performance, struct Array *array, void *src){
    /* calling write item */
    writeItem( performance, array, array->nel,src );
}

/* This function  will moves all the elements in the array by higher position giving by index */
void insertItem(struct Performance *performance, struct Array *array, unsigned int index, void *src){
    
    
    void* wordBefore = malloc(sizeof(array->width)) ;

    int i =0 ;
    /* for loop for move elements to higher position */
    for (i = array->nel-1   ; i +1 > index  ; i--)
    {

     /* read function */
        readItem( performance , array, i , wordBefore);
        

    /* write function */
        writeItem( performance, array, i + 1, wordBefore );

    }

    /* write function */
    writeItem( performance, array, index , src );

    free(wordBefore);

}

/* This function to insert data at position 0 */
void prependItem(struct Performance *performance, struct Array *array, void *src){
    insertItem( performance, array, 0 ,src );
}


/* this function will delete an item in the array  */
void deleteItem(struct Performance *performance, struct Array *array, unsigned int index){

    void* word = malloc(sizeof(array->width)) ;

    int i =0 ;
    
    for (i = index + 1 ; i < array->nel   ; i++)
    {

    
    readItem( performance , array, i , word);
        

    
    writeItem( performance, array, i - 1 , word );

    }

   
    contract(performance,array);

    free(word);


 } 

int findItem ( struct Performance * performance, struct Array * array, int(*compar)(const void *, const void *), void * target){
    void * word1 = malloc(array->width);

    //loop

    for (int i = 0; i < array->nel; i++)
    {
        readItem(performance,array,i,word1);

        //target and lement = 0
        if (compar(target,word1)==0)
        {
            // return i
            return i;
        }
        
    }
    free(word1);
    return -1;
 }

    /* this function search for element and retrieve it */
    int searchItem ( struct Performance * performance, struct Array * array, int(*compar)(const void *, const void *), void * target){

        /* lower bownd */
        int low =0 ;
        /* Upper Bownd */
         int high = array-> nel - 1;

        /* middle bownd */
        
         int mid =0;

        int *sur = malloc(array->width);
        /* do loop */
        do
        {
            int mid =(high + low)/2;

            /* read item in the mid*/
            
            readItem(performance,array,mid,sur);

            /* apply compar function to the target and the retrived elemnts */

            /* if compar function return zero that indicating a match )*/
            if (compar(sur,target) == 0 )
            {
                free(sur);
                return mid ;
            } 
            /*if compar function return less than zero that indicating precdes the target */
            else if (compar(sur,target) < 0)
            {
                low = mid +  1;
                mid =(high + low)/2;
            }  
            /*if compar function return grater than zero that indicating retrieved elements comes after the target  */
            else if (compar(sur,target) > 0)
            {
                high = mid - 1;
                mid =(high + low)/2;
            }
            
        } while (high >= low);
        

        readItem(performance,array,mid,sur);

        if (compar(sur,target) == 0 )
        {
            free(sur);
            return mid;
        }
        /* when the function didnt find a match , it will return -1 */
        return -1 ;
    }
   

