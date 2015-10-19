#include "malloc.c"

int main(int argc, char **argv) 
 {
 	
  printf("Test Case 4: (Allocating A lot of Memory )\n");
	int *ptr;
	ptr=(int*)malloc(500*sizeof(int));
	*ptr=5;
	printf("%i\n", *ptr);
	
	char *d=malloc(100*sizeof(char));
	*d='d';
	printf("%c\n", *d);
	
	char *f=malloc(100*sizeof(char));
	*f='f';
	printf("%c\n", *f);
	
	char *j=malloc(1000*sizeof(char));
	*j='j';
	printf("%c\n", *j);
	
	char *x=malloc(1000*sizeof(char));
	*x='x';
	printf("%c\n", *x);
	
  printf("Test Case 4: (Allocated Memory for Big Memory Test Cases)\n");

	return 0;
 }
