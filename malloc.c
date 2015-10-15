#include "malloc.h"
#include <stdio.h>



#define TOTALMEMORY 5000
#define NOMEM	-1


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
		return NOMEM;
	}
}
void consolidator()
{
	
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
		toInsert= (void *)& block[sizeof(entry)];
		
		entry->size=size;
		entry->next=exit;
		entry->isFree=0;
		entry->index=0;
		
		exit->next=NULL;
		exit->isFree=1;
		exit->size=sizeof(block)-(sizeof(entry)+size);
		exit->index=sizeof(entry+size);
		
		head=entry;
		
		
		
		return toInsert;
		
	}
	else
	{
		int freeBlock;
		
		struct MemoryBlock *entry;
		struct MemoryBlock *exit;
		void *toInsert;
		
		
		
		freeBlock=findBlock(size+sizeof(struct MemoryBlock));
		
		if (freeBlock==NOMEM)
		{
			fprintf(stderr, "Not enough free memory FILE: '%s' on LINE: '%d'\n", file, line);
			
			return 0;
		}
		
		entry=(struct MemoryBlock*)& block[freeBlock];
		exit = (struct MemoryBlock*)& block[freeBlock+sizeof(entry)+size];
		toInsert= (void *)& block[freeBlock+sizeof(entry)];
		
		
		exit->next=entry->next;
		entry->next=exit;
		
		entry->size=size;
		entry->isFree=0;
		entry->index=freeBlock;
		
		exit->index=(sizeof(entry+size));
		
		return toInsert;
		
	}

	return 0;
}

void myfree(void *p, char *file, int line)
{
	
}

 int main(int argc, char **argv) 
 {
	int *p=malloc(sizeof(int));
	*p=30;
	
	printf("%i", *p);
	
	return 0;
 }
