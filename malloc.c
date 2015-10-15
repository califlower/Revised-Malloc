#include "malloc.h"
#include <stdio.h>

// Use a static char array (static char myblock[5000] for your malloc() and free() to use to manage dynamic memory.

#define TOTALMEMORY 5000

struct MemoryBlock *head;
static char mymemorystoragearray[TOTALMEMORY]; //big block of memory space


void *mymalloc(unsigned int size, char *file, int line){
	
	if (size == 0) {
		fprintf(stderr, "Unable to allocate 0 bytes in FILE: '%s' on LINE: '%d'\n", file, line);
		return 0;
	}

return 0;
}

void myfree(void *p, char *file, int line);

 int main(int argc, char **argv) {
  
  return 0;
 }
