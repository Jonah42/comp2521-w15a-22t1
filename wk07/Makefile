CC=gcc
CFLAGS=-g

euler: euler.o graph.o
	$(CC) euler.o graph.o -o euler

euler.o: euler.c graph.h
	$(CC) $(CFLAGS) euler.c -o euler.o -c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) graph.c -o graph.o -c