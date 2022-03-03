#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char* A[3] = {"cat", "dog", "mouse"};
	int P[3] = {2,3,1};

	char* temp[3];
	for (int i = 0; i < 3; i++) {
		temp[P[i]-1] = A[i];
	}
	
	for (int i = 0; i < 3; i++) printf("%s\n", temp[i]);
	return 0;
}