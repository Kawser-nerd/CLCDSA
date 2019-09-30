#include <stdio.h>
void swap (int *x, int *y) { int temp;
temp = *x; *x = *y; *y = temp; } 
int partition (int array[], int left, int right){
	int i, j, pivot;
i = left; j = right + 1; pivot = left; 
 do { do { i++;} while (array[i] < array[pivot]); do { j--; } while (array[pivot] < array[j]); if (i < j) { swap(&array[i], &array[j]); } } while (i < j); swap(&array[pivot], &array[j]); return j; } /* ??????? */ void quick_sort (int array[], int left, int right) { int pivot; if (left < right) { pivot = partition(array, left, right); quick_sort(array, left, pivot-1); quick_sort(array, pivot+1, right); } }
 //kokkara
int main (void) {
int i,n,m,a;
scanf ("%d",&n);
int kore[1002];
for (i = 0; i < n; i++) { 
 scanf("%d", &kore[i]);
 	}
 quick_sort( kore, 0, n-1);
 	m=kore[n-1];
for (i = n-1; i > -1 ; i--) { 
 if(m!=kore[i])
 {
 	a=kore[i];
 	break;
 }
 	}
 printf("%d\n",a);
 return 0;
 } ./Main.c: In function ‘main’:
./Main.c:11:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&n);
 ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &kore[i]);
  ^