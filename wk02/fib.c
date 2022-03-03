//Written by Jonah Meggs for COMP2521 21T3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fib(int n) {
	printf("fib(%d)\n", n);
	assert(n > 0);
	if (n == 1 || n == 2) {
		// printf("BASE");
		return 1;
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}

int main(int argc, char* argv[]) {
	assert(argc == 2);
	int result = fib(atoi(argv[1]));
	printf("Result: %d\n", result);
	return 0;
}