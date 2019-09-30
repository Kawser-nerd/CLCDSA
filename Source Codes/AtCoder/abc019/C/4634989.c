#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)
// ???
void quicksort (int left, int right, int a[]) {
    int pivot = a[(left+right)/2];
    int i = left, j = right;
    // ???
    while (1) {
        while (a[i]  < pivot ) { i++; }
        while (a[j] > pivot ) { j--; }
        if (i >= j) {   // ????
            break;
        }
        swap(a[i], a[j]);
        i++; j--;
    }
    if (left < i-1) {
        quicksort(left, i-1, a);
    }
    if (j+1 < right) {
        quicksort(j+1, right, a);
    }
}
// ????????????
int divToOdd (int num) {
    while (num%2 == 0) {
        num = num/2;
    }
    return num;
}
// ???????????
void countUnipue (int N, int a[]) {
    for (size_t i = 0; i < N; i++) {
        a[i] = divToOdd(a[i]);
    }
    // ?????????
    quicksort(0, N-1, a);
    // ????
    /*
    for (size_t i = 0; i < N; i++) {
        printf("%2d", a[i]);
    }
    printf("\n");
    */
    // ?????????????
    int cnt = 1;
    int now = a[0];
    for (size_t i = 1; i < N; i++) {
        if (now != a[i]) {
            cnt++;
        }
        now = a[i];
    }
    printf("%d\n", cnt);
}

int main(int argc, char const *argv[]) {
    // ??
    int N;
    int *a;
    // ??
    scanf("%d", &N);
    a = (int *)malloc(sizeof(int)*N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    // ??
    countUnipue(N, a);
    // ?????
    free(a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:64:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:67:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^