#include "malloc.h"
#include <stdio.h>



#define TOTALMEMORY 5000


static char block[TOTALMEMORY]; 

int findBlock ()
{
	if (head==NULL)
		return 0;
	else
	{
		return 2;
	}
}


void *mymalloc(unsigned int size, char *file, int line)
{
	
	if (size == 0) 
	{
		fprintf(stderr, "Unable to allocate 0 bytes in FILE: '%s' on LINE: '%d'\n", file, line);
		
		return 0;
	}
	else if (head==NULL)
	{
		struct MemoryBlock *entry;
		
		entry->size=size;
		entry->next=NULL;
		entry->isFree=0;
		
		void *pointer= (void *)&block[sizeof(entry)+size];
		return pointer;
		
	}

	return 0;
}

void myfree(void *p, char *file, int line)
{
	
}

 int main(int argc, char **argv) 
 {
  
  return 0;
 }
