#include <stdio.h>

void add(int* n) {
	*n = *n + 1;
}

int main(void) {
	int x;
	x = 42;
	int *p;
	p = &x;
	add(p);
	//?????
	return 0;
}