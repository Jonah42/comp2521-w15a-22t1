#include <stdio.h>

int main(void) {
	char dummy;

	int x, y;
	char *c, *d, *e, *f;

	x = y = 2;
	c = d = "abc";
	e = "xyz"; f = "xyz";
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	printf("c: %p\n", c);
	printf("d: %p\n", d);
	printf("e: %p\n", e);
	printf("f: %p\n", f);
	scanf("%c", &dummy);

	x++;
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	scanf("%c", &dummy);
	
	*c = 'A';
	printf("c: %p\n", c);
	printf("d: %p\n", d);

	return 0;
}