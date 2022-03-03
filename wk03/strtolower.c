#include <stdio.h>
#include <ctype.h>
#include <string.h>

int my_strlen(char *s) {
	printf("Hello!\n");
	return strlen(s);
}

void strToLower(char *s) {
	int len = my_strlen(s);
	for (int i = 0; i < len; i++) {
		s[i] = tolower(s[i]);
	}
}

int main(int argc, char** argv) {
	char s[] = "rAnDoM stRiNg";
	printf("%s\n", s);
	strToLower(s);
	printf("%s\n", s);
	return 0;
}