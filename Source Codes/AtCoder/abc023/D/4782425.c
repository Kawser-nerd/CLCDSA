#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define size 100000
// ??
int N;
int H[size], S[size];
// ????
long lPow (int n, int m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 0) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// ????
void swap (double *a, double *b) {
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
// ?????
void quicksort (int left, int right, double x[]) {
    double pivot = x[(left+right)/2];
    int i = left, j = right;
    // ???
    while (1) {
        while (x[i] < pivot ) { i++; }
        while (x[j] > pivot ) { j--; }
        if (i >= j) {
            break;
        }
        swap(&x[i], &x[j]);
        i++; j--;
    }
    if (left < i-1) {
        quicksort(left, i-1, x);
    }
    if (j+1 < right) {
        quicksort(j+1, right, x);
    }
}
// ????????????????????
bool check (long Opt) {
    double t[N];    //???????????
    for (size_t i = 0; i < N; i++) {
        if ((Opt - H[i]) < 0) {
            return false;
        } else {
            t[i] = (Opt - H[i])/S[i];
        }
    }
    // ???
    quicksort(0, N-1, t);
    // ??
    for (int i = 0; i < N; i++) {
        if (t[i] < i) {
            return false;
        }
    }
    return true;
}
// ????
void binarySearch ( ) {
    long left, right;
    left = 0; right = LONG_MAX;
    // ??
    while (left+1 < right) {
        long mid = (left+right)/2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%ld\n", right);
}

// ???
int main(int argc, char const *argv[]) {
    // ??
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d", &H[i], &S[i]);
    }
    // ??
    binarySearch();
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:88:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:90:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &H[i], &S[i]);
         ^