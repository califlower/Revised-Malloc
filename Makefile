COMPILER = gcc
CFLAGS = -Wall -g -ansi -pedantic
CFLAGS2 = -g

all: malloc Test1 Test2 Test3 Test4 Test5 Test6 Test7
.PHONY: all
.PHONY: clean

malloc.o: malloc.c malloc.h
	$(COMPILER) $(CFLAGS) -c malloc.c

main.o: main.c malloc.h
	$(COMPILER) $(CFLAGS2) -c main.c
	
malloc: malloc.o main.o
	$(COMPILER) $(CFLAGS) -o malloc main.o malloc.o


Test1.o: Test1.c
	$(COMPILER) $(CFLAGS2) -c Test1.c

Test1: malloc.o Test1.o
	$(COMPILER) $(CFLAGS) -o Test1 Test1.o malloc.o


Test2.o: Test2.c
	$(COMPILER) $(CFLAGS2) -c Test2.c

Test2: malloc.o Test2.o
	$(COMPILER) $(CFLAGS) -o Test2 Test2.o malloc.o


Test3.o: Test3.c
	$(COMPILER) $(CFLAGS2) -c Test3.c

Test3: malloc.o Test3.o
	$(COMPILER) $(CFLAGS) -o Test3 Test3.o malloc.o


Test4.o: Test4.c
	$(COMPILER) $(CFLAGS2) -c Test4.c

Test4: malloc.o Test4.o
	$(COMPILER) $(CFLAGS) -o Test4 Test4.o malloc.o


Test5.o: Test5.c
	$(COMPILER) $(CFLAGS2) -c Test5.c

Test5: malloc.o Test5.o
	$(COMPILER) $(CFLAGS) -o Test5 Test5.o malloc.o


Test6.o: Test6.c
	$(COMPILER) $(CFLAGS2) -c Test6.c

Test6: malloc.o Test6.o
	$(COMPILER) $(CFLAGS) -o Test6 Test6.o malloc.o


Test7.o: Test7.c
	$(COMPILER) $(CFLAGS2) -c Test7.c

Test7: malloc.o Test7.o
	$(COMPILER) $(CFLAGS) -o Test7 Test7.o malloc.o


clean:
	rm -rf $(wildcard *.o) malloc Test1 Test2 Test3 Test4 Test5 Test6 Test7
