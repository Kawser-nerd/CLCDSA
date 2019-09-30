#include <stdio.h>
#include <math.h>
#define swap(a, b) (a+=b, b=a-b, a-=b)
// ???
void qSort (int left, int right, int a[]) {
    long pivot = a[(left+right)/2];
    int i = left, j = right;
    // ???
    while (1) {
        while (a[i]  > pivot ) { i++; }
        while (a[j] < pivot ) { j--; }
        if (i >= j) {
            break;
        }
        swap(a[i], a[j]);
        i++; j--;
    }
    if (left < i-1) {
        qSort(left, i-1, a);
    }
    if (j+1 < right) {
        qSort(j+1, right, a);
    }
}
// ?????
void calcArea (int N, int R[]) {
    double Area = 0;
    qSort(0, N-1, R);
    for (size_t i = 0; i < N; i++) {
        if (i%2 == 0) {
            Area += R[i]*R[i];
        } else {
            Area -= R[i]*R[i];
        }
    }
    Area = Area*M_PI;
    printf("%lf\n", Area);
}
// ???
int main(int argc, char const *argv[]) {
    // ??
    int N;
    // ??
    scanf("%d\n", &N);
    int R[N];
    for (size_t i = 0; i < N; i++) {
        scanf("%d", &R[i]);
    }
    // N?????
    calcArea(N, R);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &N);
     ^
./Main.c:47:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &R[i]);
         ^