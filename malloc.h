#include<stddef.h>
#define MALLOC_H

void * my_malloc( unsigned int size, char * file, int line );
void my_free( void * p, char * file, int line );


struct MemoryBlock
{
	struct MemoryBlock *next;
	int isfree; // flag which is used to tell whether the program is freed or not
	int size; // size of the block of memory
};

void MyFree(void* ptr);
