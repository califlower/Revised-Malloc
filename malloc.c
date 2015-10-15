#include "malloc.h"
#include <stdio.h>



#define TOTALMEMORY 5000


static char block[TOTALMEMORY]; 

int findBlock (unsigned int size)
{
	struct MemoryBlock iter=head;
	
	if (iter==NULL)
		
		return 0;
	else
	{
		while (iter!=NULL)
		{
			if (iter->size>=size && iter->isFree=1)
			{
				return iter->index;
			}
			iter=iter->next;
		}
		return 1;
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
		
		
		entry = (struct MemoryBlock*)& block[0];
		
		
		
		exit = (struct MemoryBlock*)& block[];
		
		
		entry->size=size;
		entry->next=NULL;
		entry->isFree=0;
		head=entry;
		
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
	malloc(2);
	return 0;
 }
