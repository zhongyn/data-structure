CC = GCC
CFLAGS = -c -Wall -std=c99

all: arrayBagStack

arrayBagStack: arrayBagStack.o
	$(CC) arrayBagStack.o -o arrayBagStack

arrayBagStack.o: arrayBagStack.c
	$(CC) $(CFLAGS) arrayBagStack.c

clean:
	rm -rf *o arrayBagStack

