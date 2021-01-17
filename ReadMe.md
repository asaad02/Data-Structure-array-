struct Array
{
unsigned int width;
unsigned int nel;
unsigned int capacity;
void *data;
};
This structure represents an array data structure (our first, and one of the simplest data
structures used in this course). The elements of the Array structure are as follows: width
represents the size in bytes of each element in the array, nel represents the number of
elements currently in the array, capacity represents the total number of elements that can be
stored in the array, and data is a pointer to the contents of the array.

Additionally, you will be using the following structure to measure the performance of your code
and count the number of memory read, memory write, malloc and free operations.
struct Performance
{
unsigned int reads;
unsigned int writes;
unsigned int mallocs;
unsigned int frees;
};
Basic function prototypes and descriptions for your assignment
struct Performance *newPerformance();
This function will allocate sufficient memory for a Performance structure, set reads, writes,
mallocs, and frees to zero (yes, I realize there is technically one malloc in this function) and
return the address of the structure. Your function should print an error message to the
standard error stream and exit if the malloc function fails.
struct Array *newArray( struct Performance *performance, unsigned int width,
unsigned int capacity );
This function will allocate sufficient memory for an Array structure, set the width and
capacity attributes of the structure to the values provided, set the nel attribute to zero, and
allocate width*capacity bytes of memory storing the address of that memory in data. It will
increment the performance->mallocs value by one (yes, I know there are technically two
mallocs performed in this function). Finally, it will return a pointer to the allocated Array
structure (not to data). You may assume that width and capacity are non-negative. Your
function should print an error message to the standard error stream and exit if the malloc
function fails.
void readItem( struct Performance *performance, struct Array *array, unsigned
int index, void *dest );
If index is greater than or equal to array->nel this function should print an error message to
the standard error stream and exit. Otherwise, this function will copy array->width bytes
from the memory address array->data offset by the index (multiplied by array->width) to
the memory address given by dest. In addition, it should add one to performance->reads.
void writeItem( struct Performance *performance, struct Array *array,
unsigned int index, void *src );
If index exceeds array->nel or exceeds or equals array->capacity this function should print
an error message to the standard error stream and exit. Otherwise, this function will copy
array->width bytes from the memory address given by src to the memory address array-
>data offset by the index (multiplied by array->width). If index exactly equals array->nel,

array->nel should be incremented by one. In addition, it should add one to performance-
>writes.
void contract( struct Performance *performance, struct Array *array );
If array->nel==0 this function should print an error message to the standard error stream and
exit. Otherwise, it should decrement array->nel by one.
void freeArray( struct Performance *performance, struct Array *array );
This function will free both array->data and the array structure itself. And it will increment
performance->frees by one (yes, one).
Derived function prototypes and descriptions for your assignment
The following functions must be implemented by calling the basic functions above (not by
interacting with data of the Array structure directly). Error handling will be done by the basic
functions.
void appendItem( struct Performance *performance, struct Array *array, void
*src );
This function will add an element to the end of the array (i.e. at position array->nel). It will do
this by calling the writeItem function (above).
void insertItem( struct Performance *performance, struct Array *array,
unsigned int index, void *src );
This function will use readItem and writeItem calls to move all the elements in the array at
the position given by index and higher, one position further back and then write the given data
at index in the array.
void prependItem( struct Performance *performance, struct Array *array, void
*src );
This function will use insertItem to insert data at position 0.
void deleteItem( struct Performance *performance, struct Array *array,
unsigned int index );
This function will use readItem and writeItem calls to move all the elements in the array at
the position given by index+1 and higher, one position forward, and then use the contract
function to remove the duplicate last entry.

The above, constitutes 80% of the assignment. If you complete it, you can get a grade up to
80% (Good). The rest of the assignment is more challenging and will allow you to get a grade of
80-90% (Excellent) or 90-100% (Outstanding). Make sure you complete the first part well,
before proceeding to the following additional part.
Write the following functions:
int findItem( struct Performance *performance, struct Array *array, int
(*compar)(const void *, const void *), void *target );
This function will retrieve elements from array using readItem (above) starting with the first
element in the array and proceeding incrementally. For each element it will apply the compar
function to target and the retrieved element. If the compar function returns 0 (indicating a
match), this function should return the index of the matching element. If they compar function
returns a non-zero value (indicating a mismatch) it should proceed with the next element. If
they function processes the entire array without finding a match, it should return a value of -1.
int searchItem( struct Performance *performance, struct Array *array, int
(*compar)(const void *, const void *), void *target );
This function will retrieve elements from array using readItem (above) starting with the
middle element in the array rounded down (i.e. if there are 10 elements indexed 0 to 9, it will
start with element 4). For each element it will apply the compar function to target and the
retrieved element. If the compar function returns 0 (indicating a match), this function should
return the index of the matching element. If the compar function returns a value of less than
zero (indicating the retrieved element precedes the target) it should repeat the search on all
higher indexed elements. If the compar function returns a value of greater than zero (indicating
the retrieved element comes after the target) it should repeat the search on all lower indexed
elements. If they function processes the final element without finding a match, it should return
a value of -1. (This is a binary search.)
