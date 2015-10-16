#include "malloc.h"
#include <stdio.h>



#define TOTALMEMORY 5000
#define NOMEM	-1


static char block[TOTALMEMORY]; 

struct MemoryBlock* findBlock (unsigned int size)
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
				return iter;
			}
			iter=iter->next;
		}
		return NULL;
	}
}
void garbagecollector()
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
		exit->index=sizeof(entry)+size;
		
		head=entry;
		
		
		
		return toInsert;
		
	}
	else
	{
	
		
		struct MemoryBlock *entry;
		struct MemoryBlock *exit;
		void *toInsert;
		
		
		entry=findBlock(size+sizeof(struct MemoryBlock));
		
		
		if (entry==NULL)
		{
			fprintf(stderr, "Not enough free memory FILE: '%s' on LINE: '%d'\n", file, line);
			
			return 0;
		}
		exit=(struct MemoryBlock*)& block[sizeof(struct MemoryBlock)+size+entry->index];
		toInsert=(void *) &block[entry->index+sizeof(struct MemoryBlock)];
		
		exit->isFree=1;
		exit->size=30;
		exit->next=entry->next;
		exit->index=entry->index+size;
		
		entry->next=exit;
		entry->isFree=0;
		entry->size=size;
		
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
	int *z=malloc(sizeof(int));
	*z=323;
	int *x=malloc(sizeof(int));
	*x=12;
	
	printf("%i\n", *p);
	printf("%i\n", *z);
	printf("%i\n", *x);
	
	return 0;
 }
