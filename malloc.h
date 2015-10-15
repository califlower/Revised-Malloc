#include<stddef.h>
#define MALLOC_H

void * my_malloc( unsigned int size, char * file, int line );

void my_free( void * p, char * file, int line );


struct MemoryBlock
{
	struct MemoryBlock *next;
	int isFree; 
	int size; 
}*head;


