#include <stdio.h>
#include <stdlib.h>

#define Item int


void swap(int* arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int less(int a, int b) {
	return a < b;
}

int partition(Item a[], int lo, int hi)
{
   Item v = a[lo];  // pivot
   int  i = lo+1, j = hi;
   for (;;) {
      while (less(a[i],v) && i < j) i++;
      while (less(v,a[j]) && j > i) j--;
      if (i == j) break;
      swap(a,i,j);
      // if (i < hi) i++;
      // if (j > 0) j--;
   }
   j = less(a[i],v) ? i : i-1;
   swap(a,lo,j);
   return j;
}

void quicksort(Item a[], int lo, int hi)
{
   int i; // index of pivot
   if (hi <= lo) return;
   i = partition(a, lo, hi);
   quicksort(a, lo, i-1);
   quicksort(a, i+1, hi);
}

void show(int *arr, int n) {
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}

int main(int argc, char** argv) {
	int *arr = malloc(argc-1*sizeof(int));
	for (int i = 1; i <= argc; i++) arr[i-1] = atoi(argv[i]);
	show(arr, argc-1);
	quicksort(arr, 0, argc-2);
	show(arr, argc-1);
}