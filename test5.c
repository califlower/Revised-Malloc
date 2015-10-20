#include "malloc.h"

int main(int argc, char **argv) 
 {
 	
printf("Test Case 5: (Allocating To Much Memory )\n");
	
	char *d=malloc(10000*sizeof(char));

  printf("Test Case 5: (Allocated To Much Memory Test Cases)\n");

	return 0;
 }
