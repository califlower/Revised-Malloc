#include "malloc.h"
#define TOTALMEMORY 5000

static char block[TOTALMEMORY]; 

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

struct MemoryBlock* findBigBlock (unsigned int size)
{
	struct MemoryBlock *iter=BigHead;
	
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


	if (size<=4)
	{
		/*Cannot allocate something with no size */
		if (size <= 0) 
		{
			fprintf(stderr, "Unable to allocate 0 bytes in FILE: '%s' on LINE: '%d'\n", file, line);
			
			return NULL;
		}
		
		/*if head is empty. AKA first time malloc is ran */
		else if (!head)
		{
			
			
			struct MemoryBlock *end;
			
			head = (struct MemoryBlock*) &block[0];		
			end = (struct MemoryBlock*)& block[sizeof(struct MemoryBlock)+size];
			
			
			head->size=size;
			head->next=end;
			head->isFree=0;
		
			
			end->next=NULL;
			end->isFree=1;
			end->size=(sizeof(block)/2)-(sizeof(struct MemoryBlock)+size);
				
			
			return (char *) head+sizeof(struct MemoryBlock);
			
		}
		/* on all other runs */
		else
		{	
			
			struct MemoryBlock *entry;
			struct MemoryBlock *end;
		
			entry=findBlock(size+sizeof(struct MemoryBlock));
			
			if (!entry)
			{
				fprintf(stderr, "No more available space, error in FILE:'%s' on LINE:'%d'\n", file, line);
				return NULL;
			}
			
			end=(struct MemoryBlock*)entry+size;
				
			if (!entry->next)
			{
				end->size=entry->size-(size+sizeof(struct MemoryBlock));
				end->next=NULL;
			}
			else
			{
				end->size=entry->next->size-(entry->size-(size+sizeof(struct MemoryBlock)));
				end->next=entry->next;
			}
			
			end->isFree=1;
			
			entry->size=size;
			entry->next=end;
			entry->isFree=0;
				
			
			return (char *) entry+ sizeof(struct MemoryBlock);
			
		
		}
	}
	else
	{
		/*Cannot allocate something with no size */
		if (size <= 0) 
		{
			fprintf(stderr, "Unable to allocate 0 bytes in FILE: '%s' on LINE: '%d'\n", file, line);
			
			return NULL;
		}
		
		/*if head is empty. AKA first time malloc is ran */
		else if (!BigHead)
		{
			
			
			struct MemoryBlock *end;
			
			BigHead = (struct MemoryBlock*) &block[TOTALMEMORY/2];		
			end = (struct MemoryBlock*)& block[(TOTALMEMORY/2)+sizeof(struct MemoryBlock)+size];
			
			
			BigHead->size=size;
			BigHead->next=end;
			BigHead->isFree=0;
		
			
			end->next=NULL;
			end->isFree=1;
			end->size=(sizeof(block)/2)-(sizeof(struct MemoryBlock)+size);
				
			
			return (char *) BigHead+sizeof(struct MemoryBlock);
			
		}
		/* on all other runs */
		else
		{	
			
			struct MemoryBlock *entry;
			struct MemoryBlock *end;
		
			entry=findBlock(size+sizeof(struct MemoryBlock));
			
			if (!entry)
			{
				fprintf(stderr, "No more available space, error in FILE:'%s' on LINE:'%d'\n", file, line);
				return NULL;
			}
			
			end=(struct MemoryBlock*)entry+size;
				
			if (!entry->next)
			{
				end->size=entry->size-(size+sizeof(struct MemoryBlock));
				end->next=NULL;
			}
			else
			{
				end->size=entry->next->size-(entry->size-(size+sizeof(struct MemoryBlock)));
				end->next=entry->next;
			}
			
			end->isFree=1;
			
			entry->size=size;
			entry->next=end;
			entry->isFree=0;
				
			
			return (char *) entry+ sizeof(struct MemoryBlock);
			
		
		}
	}

	
}

void myfree(void *p, char *file, int line)
{
	if (p == NULL)
	{
		fprintf(stderr, "Null pointer in FILE:'%s' on LINE:'%d'\n", file, line);
		return;
	}
	
	
	struct MemoryBlock *del= (struct MemoryBlock*)((char*)p - sizeof(struct MemoryBlock));
	
	if (!del )
	{
		fprintf(stderr, "Pointer doesn't exist, in FILE:'%s' on LINE:'%d'\n", file, line);
	}
	else if (del->size<=4)
	{
		struct MemoryBlock *iter=head;

		
		if (del->isFree==1)
		{
			fprintf(stderr, "Already freed pointer, error in FILE:'%s' on LINE:'%d'\n", file, line);
			return;
		}

		else
		{
			
			del->isFree=1;
		}	

		while (iter && iter->next)
		{
				
			if (iter->isFree==1 && iter->next->isFree==1)
			{
				iter->size+=iter->next->size;
				iter->next=iter->next->next;
			}
			iter=iter->next;
		}
		return;
		
	}
	else
	{
		struct MemoryBlock *iter=BigHead;

		
		if (del->isFree==1)
		{
			fprintf(stderr, "Already freed pointer, error in FILE:'%s' on LINE:'%d'\n", file, line);
			return;
		}

		else
		{
			
			del->isFree=1;
		}	

		while (iter && iter->next)
		{
				
			if (iter->isFree==1 && iter->next->isFree==1)
			{
				iter->size+=iter->next->size;
				iter->next=iter->next->next;
			}
			iter=iter->next;
		}
		return;
		
	}
	
}

