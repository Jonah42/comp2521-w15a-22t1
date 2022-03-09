#include <stdio.h>
#include <string.h>

int add(int a, int b) {
	return a+b;
}

int mul(int a, int b) {
	return a*b;
}

int main(void) {

	int x = 42;
	int y = 3;

	int (*op)(int, int);

	op = add;

	printf("%d\n", op(x,y));

	op = mul;
	printf("%d\n", op(x,y));


	return 0;
}