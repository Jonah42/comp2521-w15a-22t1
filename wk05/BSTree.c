// Rotation example, Jonah Meggs COMP2521 21T3


#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node BSTNode;
typedef Tree BSTree;

BSTree createNode(int value) {
	BSTree new = malloc(sizeof(*new));
	new->left = new->right = NULL;
	new->value = value;
	return new;
}


BSTree rotateRight(BSTree t) {
	if (t == NULL || t->left == NULL) return t;
	BSTree newRoot = t->left;
	t->left = t->left->right;
	newRoot->right = t;
	return newRoot;
}

BSTree rotateLeft(BSTree t) {
	if (t == NULL || t->right == NULL) return t;
	BSTree newRoot = t->right;
	t->right = t->right->left;
	newRoot->left = t;
	return newRoot;
}

BSTree insert(BSTree t, int value) {
	if (t == NULL) return createNode(value);
	if (value < t->value) t->left = insert(t->left, value);
	else t->right = insert(t->right, value);
	return t;
}

// BSTree insertAVL(BSTree t, int value) {
// 	return NULL;
// }

int main(int argc, char **argv) {
	BSTree t = NULL;
	for (int i = 1; i < argc; i++) t = insert(t, atoi(argv[i]));
	printTree(t);
	while (1) {
		char buf[100];
		scanf("%s", buf);
		if (strcmp(buf, "left") == 0) {
			t = rotateLeft(t);
		} else if (strcmp(buf, "right") == 0) {
			t = rotateRight(t);
		// } else if (strcmp(buf, "avl") == 0) {
		// 	int x;
		// 	scanf("%d", &x);
		// 	t = insertAVL(t, x);
		} else {
			printf("No clue watchya talking bout\n");
			continue;
		}
		printTree(t);
	}
	
	return 0;
}