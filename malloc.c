#include "mymalloc.h"
#define MEMBLOCK 5000
// Use a static char array (static char myblock[5000] for your malloc() and free() to use to manage dynamic memory.

static char myblock[MEMBLOCK]; //big block of memory space

// Basic function of malloc(size t size) is to return a pointer to a block of the requested size.
void *mymalloc(unsigned int size, char *file, int line)
{

}

void myfree(void *p, char *file, int line){


}
