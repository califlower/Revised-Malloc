#include "malloc.c"

int main(int argc, char **argv) 
 {
 	
  printf("Test Case 2: (Allocating Memory for a Double)\n");
	double *p=malloc(sizeof(double));
	*p=30.0;
	double *x=malloc(sizeof(double));
	*x=2;
	double *y=malloc(sizeof(double));
	*y=1.3;
	double *m=malloc(sizeof(double));
	*m=40;
	double *n=malloc(sizeof(double));
	*n=50.123;
	double *a=malloc(sizeof(double));
	*a=-502.1521;
	double *u=malloc(sizeof(double));
	*u=0.02414;

	printf("%g\n", *p);
	printf("%g\n", *x);
	printf("%g\n", *y);
	printf("%g\n", *m);
	printf("%g\n", *n);
  	printf("%g\n", *a);
	printf("%g\n", *u);

  printf("Test Case 2: (Allocated Memory for All Double Test Cases)\n");

	return 0;
 }
