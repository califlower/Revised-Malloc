#include "malloc.c"
int main(int argc, char **argv) 
{

 printf("----------------------------------------------------\n");

 printf("Test Case 1: (Allocating Memory for an Int)\n");

	int *p=malloc(sizeof(int));
	*p=30;
	free(p);
	printf("%i\n", *p);
 printf("----------------------------------------------------\n");
 printf("Test Case 2: (Allocating Memory for a Double)\n");

	
	double *x=malloc(sizeof(double));
	*x=2.0;
	printf("%g\n", *x);
printf("----------------------------------------------------\n");
printf("Test Case 3: (Allocating Memory for a Character)\n");

	char *y=malloc(sizeof(char*));
	*y='d';
	printf("%c\n", *y);
printf("----------------------------------------------------\n");
printf("Test Case 4: (Allocating A lot of Memory )\n");
	int *ptr;
	ptr=(int*)malloc(1000*sizeof(int));
	*ptr=5;
	printf("%i\n", *ptr);
printf("----------------------------------------------------\n");
printf("Test Case 5: (Allocating To Much Memory )\n");
	
	
printf("----------------------------------------------------\n");
printf("Test Case 6: (Freeing Space To Add Memory )\n");	

return 0;
 }
