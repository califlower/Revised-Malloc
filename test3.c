#include "malloc.c"

int main(int argc, char **argv) 
 {
 	
  printf("Test Case 3: (Allocating Memory for a Character)\n");

	char *z=malloc(10*sizeof(char));
	*z='z';
	printf("%c\n", *z);
	
	char *d=malloc(100*sizeof(char));
	*d='d';
	printf("%c\n", *d);
	
	char *f=malloc(100*sizeof(char));
	*f='f';
	printf("%c\n", *f);
	
	char *j=malloc(1000*sizeof(char));
	*j='j';
	printf("%c\n", *j);
	
  printf("Test Case 3: (Allocated Memory for All Character Test Cases)\n");

	return 0;
 }
