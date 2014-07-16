CC = gcc
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = student.o sort.o

studentSort: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o studentSort

student.o: student.c
	$(CC) $(CFLAGS) student.c

sort.o: sort.c
	$(CC) $(CFLAGS) sort.c

clean:
	rm -rf *.o *~ studentSort

