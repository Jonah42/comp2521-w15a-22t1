// Jonah Meggs 2521, ternary intro

#include <stdio.h>

int main(void) {
	while (1) {
		int ch = getchar();

		char *type;
		if (isdigit(ch)) {
		    type = "digit";
		} else {
		    type = "non-digit";
		}

		type = isdigit(ch) ? "digit" : "non-digit";

		printf("'%c' is a %s\n", ch, type);
	}

	return 0;
}