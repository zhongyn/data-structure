CC = gcc
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = main.o dynArr.o heap.o compare.o


toDoList: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o toDoList

main: main.c
	$(CC) $(LFLAGS) main.c

dynArr.o: dynArr.c
	$(CC) $(CFLAGS) dynArr.c

heap.o: heap.c
	$(CC) $(CFLAGS) heap.c

compare.o: compare.c
	$(CC) $(CFLAGS) compare.c

clean:
	rm -rf *.o *~ toDoList

