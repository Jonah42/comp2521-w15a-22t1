#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
struct Node {
	int value;
	List next;
};

List append(List l, int x) {
	List new = malloc(sizeof(struct Node));
	new->value = x;
	new->next = l;
	return new;
}

void show(List l) {
	List curr = l;
	while (curr != NULL) {
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int less(int x, int y) {
	return (x < y);
}

void swap(List l1, List l2) {
	int tmp = l1->value;
	l1->value = l2->value;
	l2->value = tmp;
}

List selectionSort(List ls) {
	List i, j, min;
  for (i = ls; i != NULL; i = i->next) {
      min = i;
      for (j = i->next; j != NULL; j = j->next) {
         if (less(j->value,min->value)) min = j;
      }
      swap(i, min);
  }
  return ls;
}

int main(int argc, char** argv) {
	List l = NULL;
	for (int i = argc - 1; i > 0; i--) l = append(l, atoi(argv[i]));
	show(l);
	selectionSort(l);
	show(l);
}