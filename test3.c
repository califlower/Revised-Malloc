#include "malloc.h"

int main(int argc, char **argv) 
 {
 	
  printf("Test Case 3: (Allocating Memory for a Character)\n");

	char *z=malloc(1000*sizeof(char));
	*z='z';
	printf("%c\n", *z);
	
	char *d=malloc(100*sizeof(char));
	*d='d';
	printf("%c\n", *d);
	
	char *f=malloc(100*sizeof(char));
	*f='f';
	printf("%c\n", *f);
	
	char *t=malloc(sizeof(char));
	*t='t';
	printf("%c\n", *t);
	
  printf("Test Case 3: (Allocated Memory for All Character Test Cases)\n");

	return 0;
 }
