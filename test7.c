#include "malloc.c"

int main(int argc, char **argv) 
 {
 	
printf("Test Case 7: (Redundant Freeing of Pointer)\n");	

	int *p=malloc(500*sizeof(int));
	*p=5;
	printf("%i\n", *p);
	free(p);
	free(p);
	p=malloc(500*sizeof(int));
	printf("%i\n", *p);
	free(p);
	p=malloc(500*sizeof(int));
	printf("%i\n", *p);
	
  printf("Test Case 7: Pointer Allocated Memory, Freed, then Allocated Again\n");

	return 0;
}
