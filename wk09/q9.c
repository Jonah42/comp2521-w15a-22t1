#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	FILE * fp1 = fopen(argv[1], "r");
	FILE * fp2 = fopen(argv[2], "r");

	int in1, in2, eof1, eof2;

	eof1 = fscanf(fp1, "%d", &in1);
	eof2 = fscanf(fp2, "%d", &in2);

	while (eof1 == 1 && eof2 == 1) {
		while (in1 <= in2 && eof1 == 1) {
			printf("%d ", in1);
			eof1 = fscanf(fp1, "%d", &in1);
		}
		while (in2 < in1 && eof2 == 1) {
			printf("%d ", in2);
			eof2 = fscanf(fp2, "%d", &in2);
		}
	}

	while (eof1 == 1) {
		printf("%d ", in1);
		eof1 = fscanf(fp1, "%d", &in1);
	}
	while (eof2 == 1) {
		printf("%d ", in2);
		eof2 = fscanf(fp2, "%d", &in2);
	}

	printf("\n");

	fclose(fp1);
	fclose(fp2);

	return 0;
}