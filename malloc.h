#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MALLOC_H
#define MALLOC_H

#define malloc( x ) mymalloc( x , __FILE__ , __LINE__ )
#define free( x ) myfree( x , __FILE__ , __LINE__ )


#define MEMBLOCK 5000


void * mymalloc( unsigned int size, char * file, int line );

void myfree( void * p, char * file, int line );

// add functions for each detectable errors

#endif