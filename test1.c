#include "malloc.c"
int main(int argc, char **argv) 
 {
 
 printf("Test Case 1: (Allocating Memory for Small Integars)\n");
	int *p=malloc(sizeof(int));
	*p=30;
	int *x=malloc(sizeof(int));
	*x=2;
	int *y=malloc(sizeof(int));
	*y=1;
	int *m=malloc(sizeof(int));
	*m=40;
	int *n=malloc(sizeof(int));
	*n=40;
	int *a=malloc(sizeof(int));
	*a=40;
	int *u=malloc(sizeof(int));
	*u=40;

	printf("%i\n", *p);
	printf("%i\n", *x);
	printf("%i\n", *y);
	printf("%i\n", *m);
	printf("%i\n", *n);
	printf("%i\n", *u);

	return 0;
 }
