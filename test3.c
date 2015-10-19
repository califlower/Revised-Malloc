#include "malloc.c"

int main(int argc, char **argv) 
 {
 	
  printf("Test Case 3: (Allocating Memory for a Character)\n");

	char *z=malloc(sizeof(char*));
	*z='z';
	char *x=malloc(sizeof(char));
	*x='x';
	char *y=malloc(sizeof(char));
	*y='y';
	char *m=malloc(sizeof(char));
	*m='m';
	char *n=malloc(sizeof(char));
	*n='n';
	char *a=malloc(sizeof(char));
	*a='a';
	char *u=malloc(sizeof(char));
	*u='u';
	
	printf("%c\n", *z);
	printf("%c\n", *x);
	printf("%c\n", *y);
	printf("%c\n", *m);
	printf("%c\n", *n);
  	printf("%c\n", *a);
	printf("%c\n", *u);

  printf("Test Case 2: (Allocated Memory for All Character Test Cases)\n");

	return 0;
 }
