#include "malloc.h"

int main(int argc, char **argv) 
 {
 	
printf("Test Case 6: (Freeing Space To Add Memory)\n");	

	int *p=malloc(500*sizeof(int));
	int *d=malloc(500*sizeof(int));
	*p=15;
	*d=25;
	printf("%i\n", *p);
	printf("%i\n", *d);
	
	
	int *x=malloc(600*sizeof(int));
	printf("Freeing other stuff to clear space for new int!\n");

	free(p);
	free(d);
	x=malloc(600*sizeof(int));
	*x=20;
	printf("%i\n", *x);
	
	
  printf("Test Case 6: (Freed Space to Add Memory)\n");

	return 0;
}
