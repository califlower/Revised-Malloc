#include "malloc.h"
#include <stdio.h>



#define TOTALMEMORY 5000


static char block[TOTALMEMORY]; 

int findBlock (unsigned int size)
{
	struct MemoryBlock *iter=head;
	
	if (iter==NULL)
		
		return 0;
	else
	{
		while (iter!=NULL)
		{
			if (iter->size>=size && iter->isFree==1)
			{
				return iter->index;
			}
			iter=iter->next;
		}
		return NULL;
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
		struct MemoryBlock *exit;
		void *toInsert;
		
		entry = (struct MemoryBlock*)& block[0];		
		exit = (struct MemoryBlock*)& block[sizeof(entry)+size];
		toInsert= (void *)&block[sizeof(entry)];
		
		entry->size=size;
		entry->next=exit;
		entry->isFree=0;
		entry->index=0;
		
		exit->next=NULL;
		exit->isFree=1;
		exit->index=sizeof(entry+size);
		
		head=entry;
		
		
		
		return toInsert;
		
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
