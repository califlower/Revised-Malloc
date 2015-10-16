#include<stddef.h>
#include <stdlib.h>
#define MALLOC_H

#define malloc( x ) mymalloc( x , __FILE__ , __LINE__ )
#define free( x ) myfree( x , __FILE__ , __LINE__ )

void *mymalloc( unsigned int size, char * file, int line );

void myfree( void * p, char * file, int line );


struct MemoryBlock
{
	struct MemoryBlock *next;
	int isFree; 
	int index;
	
	unsigned int size; 
}*head;


