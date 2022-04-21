#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int a;
	int b;
} Item;

int itemCmp(const void* a, const void* b) {
	Item ia = *(Item*)a;
	Item ib = *(Item*)b;
	return ia.a - ib.a;
}

int isStableSort(Item original[], Item sorted[], int size) {
	return 0;
}

void insertionSort(Item a[], int lo, int hi){
   int i, j;
   Item val;
   for (i = lo+1; i <= hi; i++) {
      val = a[i];
      for (j = i; j > lo; j--) {
         if (val.a >= a[j-1].a) break;
         a[j] = a[j-1];
      }
      a[j] = val;
   }
}

void printArray(Item a[], int n) {
	printf("{");
	for (int i = 0; i < n; i++) {
		printf("{%d,%d},", a[i].a, a[i].b);
	}
	printf("}\n");
}

int main(void) {
	Item itemArray[10] = {{9,1},{8,2},{9,3},{8,4},{9,5},{9,6},{9,7},{8,8},{9,10},{9,11}};
	Item itemArrayOriginal[10] = {{9,1},{9,2},{9,3},{9,4},{9,5},{9,6},{9,7},{9,8},{9,10},{9,11}};
	qsort(itemArray, 10, sizeof(Item), itemCmp);
	printf("Is stable sort? %s\n", isStableSort(itemArrayOriginal, itemArray, 10) ? "yes" : "no");
	printArray(itemArray, 10);
	Item itemArray2[10] = {{9,1},{9,2},{9,3},{9,4},{9,5},{9,6},{9,7},{9,8},{9,10},{9,11}};
	Item itemArrayOriginal2[10] = {{9,1},{9,2},{9,3},{9,4},{9,5},{9,6},{9,7},{9,8},{9,10},{9,11}};
	insertionSort(itemArray2, 0,9);
	printf("Is stable sort? %s\n", isStableSort(itemArrayOriginal2, itemArray2, 10) ? "yes" : "no");
	printArray(itemArray2, 10);
	return 0;
}