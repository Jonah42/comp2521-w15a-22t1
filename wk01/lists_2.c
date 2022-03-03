// Jonah Meggs COMP2521

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

typedef Node *List; // pointer to first node

List append(List l, int x) {
	Node* new = malloc(sizeof(Node));
	new->value = x;
	new->next = l;
	return new;
}

void show(List l) {
	Node* curr = l;
	while (curr != NULL) {
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int loop_sum(List l) {
	Node * curr = l;
	int total = 0;
	while (curr != NULL) {
		total += curr->value;
		curr = curr->next;
	}
	return total;
}

int recursive_sum(List l) {
	if (l == NULL) return 0;
	return l->value + recursive_sum(l->next);
}

int main(void) {
	List l = NULL;
	char cmd[100];
	int num;
	while (1) {
		scanf("%s", cmd);
		if (strcmp(cmd, "append") == 0) {
			scanf("%d", &num);
			l = append(l, num);
		} else if (strcmp(cmd, "gen") == 0) {
			scanf("%d", &num);
			for (int i = 0; i < num; i++) {
				l = append(l, rand()%100);
			}
		} else if (strcmp(cmd, "sum-loop") == 0) {
			printf("Sum (loop): %d\n", loop_sum(l));
		} else if (strcmp(cmd, "sum-recursive") == 0) {
			printf("Sum (recursive): %d\n", recursive_sum(l));
		} else if (strcmp(cmd, "show") == 0) {
			show(l);
		} else {
			printf("Unknown command\n");
		}
	}
	return 0;
}