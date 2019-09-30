#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_max 100
// Swap
void Swap (int x[],int a, int b) {
    int tmp;
    tmp = x[a]; x[a] = x[b]; x[b] = tmp;
}
// Qsort
void Qsort (int array[], int left, int right) {
    int i, j;
    int pivot;
    i = left; j = right;
    pivot = array[(i+j)/2];

    while (1) {
        while (array[i] > pivot) { i++; }
        while (pivot > array[j]) { j--; }
        if (i >= j) {
            break;
        }
        Swap(array, i, j);
        i++;  j--;
    }
    if (left < i-1) {   // ????????????????
        Qsort( array, left, i-1 );
    }
    if (j+1 < right) {
        Qsort( array, j+1, right );
    }
}

int main(int argc, char const *argv[]) {
    // ??
    int N;
    int A[N_max];
    // ??
    scanf("%d", &N );
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &A[i] );
    }
    // ???
    Qsort(A, 0, N-1);
    // 2???????????
    int No = 0;
    while (No <= N-1) {
        if (A[0] != A[No]) {
            printf("%d\n", A[No] );
            break;
        }
        No ++;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^
./Main.c:41:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &A[i] );
         ^