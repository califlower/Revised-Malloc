COMPILER = gcc
CCFLAGS  = -Wall -ansi -pedantic
all: sl
malloc.o: malloc.c malloc.h
	$(COMPILER) $(CCFLAGS) -c malloc.c
main.o: main.c malloc.h
	$(COMPILER) $(CCFLAGS) -c main.c
libsl.a: malloc.o
	ar rvs libsl.a malloc.o
sl: main.o libsl.a
	$(COMPILER) $(CCFLAGS) -o sl main.o libsl.a
clean:
	.PHONY: clean
	rm  s1
	rm -rf *.o