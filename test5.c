#include "malloc.c"

int main(int argc, char **argv) 
 {
 	
printf("Test Case 5: (Allocating To Much Memory )\n");
	
	char *d=malloc(10000*sizeof(char));
	*d='d';
	printf("%c\n", *d);
	
	
  printf("Test Case 3: (Allocated To Much Memory Test Cases)\n");

	return 0;
 }
