#include "malloc.h"
#include <stdio.h>




#define TOTALMEMORY 5000
#define NOMEM	-1


static char block[TOTALMEMORY]; 

struct MemoryBlock
{
	struct MemoryBlock *next;
	int isFree; 
	
	unsigned int size; 
}*head;




struct MemoryBlock* findBlock (unsigned int size)
{
	struct MemoryBlock *iter=head;
	
	while (iter)
	{
			
		if (iter->size>=size && iter->isFree==1)
		{
			return iter;
		}
		iter=iter->next;
	}
	return NULL;

}


void *mymalloc(unsigned int size, char *file, int line)
{
	
	if (size == 0) 
	{
		fprintf(stderr, "Unable to allocate 0 bytes in FILE: '%s' on LINE: '%d'\n", file, line);
		
		return 0;
	}
	else if (!head)
	{
		
		
		struct MemoryBlock *end;
		
		head = (struct MemoryBlock*) &block[0];		
		end = (struct MemoryBlock*)& block[sizeof(struct MemoryBlock)+size];
		
		
		head->size=size;
		head->next=end;
		head->isFree=0;
	;
		
		end->next=NULL;
		end->isFree=1;
		end->size=sizeof(block)-(sizeof(struct MemoryBlock)+size);
			
		return (char *) head+sizeof(struct MemoryBlock);
		
	}
	else
	{
	
		
		struct MemoryBlock *entry;
		struct MemoryBlock *end;
	
		
		
		entry=findBlock(size+sizeof(struct MemoryBlock));
		end=(struct MemoryBlock*)entry+size;
		
		end->size=entry->size-(size+sizeof(struct MemoryBlock));
		entry->size=size;
		entry->next=end;
		entry->isFree=0;
		
		end->next=NULL;
		end->isFree=1;
		
		printf("%i\n", end->size);
		
		return (char *) entry+ sizeof(struct MemoryBlock);
		
		
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
	int *x=malloc(sizeof(int));
	*x=2;
	int *y=malloc(sizeof(int));
	*y=1;
	int *m=malloc(sizeof(int));
	*m=40;
	int *n=malloc(sizeof(int));
	*n=40;
	int *a=malloc(sizeof(int));
	*a=40;


	printf("%i\n", *p);
	printf("%i\n", *x);
	printf("%i\n", *y);
	printf("%i\n", *m);
	printf("%i\n", *n);
	
	return 0;
 }
