
#ifndef MALLOC_H
#define MALLOC_H

void * my_malloc( unsigned int size, char * file, int line );
void my_free( void * p, char * file, int line );
