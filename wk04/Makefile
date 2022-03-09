CC=gcc

BSTree: BSTree.o tree.o
	$(CC) BSTree.o tree.o -o BSTree
BSTree.o: BSTree.c tree.h
	$(CC) BSTree.c -c
tree.o: tree.c tree.h
	$(CC) tree.c -c
