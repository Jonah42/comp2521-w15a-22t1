CC=gcc
CFLAGS=-g

q2: q2.o graph.o Set.o
	$(CC) q2.o graph.o Set.o -o q2

q2.o: q2.c graph.h
	$(CC) $(CFLAGS) q2.c -o q2.o -c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) graph.c -o graph.o -c

Set.o: Set.c Set.h
	$(CC) $(CFLAGS) Set.c -o Set.o -c