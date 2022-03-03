#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char word[10] = "racecar";
	
	int l, r;
	for (l = 0, r = strlen(word)-1; l < r && word[l] == word[r]; l++, r--); //n/2 -> O(n)
	// while (l < r && word[l] == word[r]) {
	// 	l++;
	// 	r--;
	// }
	printf(l < r ? "no\n" : "yes\n");
	// if (l < r) printf("no\n");
	// else printf("yes\n");
	return 0;
}
