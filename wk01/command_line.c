// 2521 Tut1 command line Q, Jonah Meggs
// Simple program to shed light upon the mysteries of argc and argv

#include <stdio.h>

int main(int argc, char ** argv) {
	printf("Argc is %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("Arg %d is: %s\n", i+1, argv[i]);
	}
	return 0;
}