#include "mymalloc.h"

// Use a static char array (static char myblock[5000] for your malloc() and free() to use to manage dynamic memory.

static char myblock[MEMBLOCK]; //big block of memory space

struct MemEntry
{
	struct MemEntry *prev, *next;
	int isfree;		// 1 - yes, 0 - no
	int size;
};
*head;

// Basic function of malloc(size t size) is to return a pointer to a block of the requested size.
void *mymalloc(unsigned int size, char *file, int line)
{

}
// function returns the allocated block to the memory resource, making it available to use in later malloc() calls.
void myfree(void *p, char *file, int line){


}
