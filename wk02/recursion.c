//Written by Jonah Meggs for COMP2521 21T3

#include <stdio.h>

int recursive_factorial(int n) {
	//BASE CASE
	if (n == 1) return 1;
	// GENERAL CASE
	return n * recursive_factorial(n-1);
}

int main(void) {
	int i;
	recursive_factorial(4);
	return 0;
}