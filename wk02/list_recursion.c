//Written by Jonah Meggs for COMP2521 21T3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

List append(List l, int x) {
	Node* new = malloc(sizeof(Node));
	new->data = x;
	new->next = l;
	return new;
}

void show(List l) {
	Node* curr = l;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int listLength(List l) {
	// BASE CASE
	if (l == NULL) {
		return 0;
	}
	// GENERAL CASE
	return 1+listLength(l->next);
}

int listCountOdds(List l) {
	// BASE
	if (l == NULL) return 0;
	// GENERAL
	return (l->data%2 == 1) + listCountOdds(l->next);
}

bool listIsSorted(List l) { // increasing
	if (l == NULL || l->next == NULL) return true;
	return (l->data <= l->next->data) && listIsSorted(l->next);
}

List listDelete(List l, int value) {
	if (l == NULL) return l;
	if (l->data == value) {
		List tmp = l->next;
		free(l);
		return tmp;
	}
	l->next = listDelete(l->next, value);
	return l;
}

List listDeleteEvens(List l) {
	if (l == NULL) return l;
	l->next = listDeleteEvens(l->next);
	if (l->data%2 == 0) {
		List tmp = l->next;
		free(l);
		return tmp;
	}
	return l;
}

int main(int argc, char* argv[]) {
	List l = NULL;
	for (int i = argc - 1; i > 0; i--) l = append(l, atoi(argv[i]));
	show(l);
	int length = listLength(l);
	int odds = listCountOdds(l);
	bool isSorted = listIsSorted(l);
	printf("Hello\n");
	printf("Length: %d\nOdds: %d\nSorted: %s\n", length, odds, isSorted?"Yes":"No");
	l = listDelete(l, 2);
	printf("After delete: \n");
	show(l);
	l = listDeleteEvens(l);
	printf("After deleteEvens: \n");
	show(l);
	return 0;
}