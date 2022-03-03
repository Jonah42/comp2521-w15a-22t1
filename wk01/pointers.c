// 2521 Jonah Meggs
// Lets get our hands dirty with pointers

#include <stdio.h>

void addition(int*);
void address(int*);

int main(void) {
	int x = 42;
	int* ptr = (&x);
	int y = (*ptr);
	printf("Size of a pointer is %d\n", sizeof(ptr));
	printf("x is %d, address of x is 0x%p, y is %d\n", x, ptr, y);
	return 0;
}