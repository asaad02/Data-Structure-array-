/**
 * @file array.c
 * @author Abdullah Saad
 * @date september 28 2020
 * @brief File containing the function prototypes
 **/


/*this structure represent an array data structure */
struct Array{
    unsigned int width;     /*size of the bytes of each elements in array*/
    unsigned int nel;       /* number of the elemnts in the array */
    unsigned int capacity;  /* total elemnts in the array that can be stored */
    void *data;             /* dtat pointer to the contant of the array */
};

/* structure to measure the performance of the code and Algorithms.*/
struct Performance{
    unsigned int reads;     /*  how many reads operations    */
    unsigned int writes;    /*  how many writes operations   */
    unsigned int mallocs;   /*  haw many maloocs operation   */
    unsigned int frees;     /*  how many frees operations    */
};

/* this function allocate memory for the performance struct and return the address of the the structure */
struct Performance *newPerformance();

/* This function allocate memory for the array structure and set the value provided and return new array */
struct Array *newArray(struct Performance *performance, unsigned int width, unsigned int capacity );

/* This function read the item and copy it to the des void dest*/
void readItem( struct Performance *performance, struct Array *array, unsigned int index, void *dest );

/* this function will write the from the src to the array data */
void writeItem( struct Performance *performance, struct Array *array, unsigned int index, void *src);

/* This function will print error message otherwise will decrement array nel */
void contract(struct Performance *performance, struct Array *array);

/* This function  will free array data and array structer*/
void freeArray( struct Performance *performance, struct Array *array );

/* Derived functions */

/* add elemnts to the end of the array */
void appendItem( struct Performance *performance, struct Array *array, void *src);

/* This function  will moves all the elements in the array by higher position giving by index */
void insertItem(struct Performance *performance, struct Array *array, unsigned int index, void *src);

/* this function will insert item at postion 0 */
void prependItem(struct Performance *performance, struct Array *array, void *src);

/* This function to insert data at position 0 */
void prependItem(struct Performance *performance, struct Array *array, void *src);

/* this function will delete an item in the array */
void deleteItem(struct Performance *performance, struct Array *array, unsigned int index);

/* find item */
int findItem ( struct Performance * performance, struct Array * array, int(*compar)(const void *, const void *), void * target);

