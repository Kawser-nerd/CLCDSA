#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max(a, b) (a>b ? a:b)
// ??
typedef struct point {
    double x, y;
    double w;   // ??
} point_t;
// ??????
double calcSqDistance (point_t a, point_t b) {
    double distance;
    double A, B;
    A = a.x-b.x; B = a.y-b.y;
    distance = A*A+B*B;
    return distance;
}
// ???????
point_t calcCenter (int N, point_t a[]) {
    point_t center;
    double weight = 0;
    for (size_t i = 0; i < N; i++) {
        weight += a[i].w;
        center.x += a[i].w*a[i].x;
        center.y += a[i].w*a[i].y;
    }
    center.x /= weight;
    center.y /= weight;
    return center;
}
// ?????
void  InitWeight (int N, point_t a[]) {
    for (size_t i = 0; i < N; i++) {
        a[i].w = 1;
    }
}
// ???????
void calcExpansionRate (int N, point_t A[], point_t B[]) {
    point_t CenterA, CenterB;
    InitWeight(N, A); InitWeight(N, B);
    CenterA = calcCenter(N, A);
    CenterB = calcCenter(N, B);
    // ???????????????
    double maxDisA = 0, maxDisB = 0;
    for (size_t i = 0; i < N; i++) {
        maxDisA = max(maxDisA, calcSqDistance(CenterA, A[i]));
        maxDisB = max(maxDisB, calcSqDistance(CenterB, B[i]));
    }
    // ????
    double ExpansionRate;
    ExpansionRate = maxDisB/maxDisA;
    ExpansionRate = sqrt(ExpansionRate);
    // ??
    printf("%.10lf\n", ExpansionRate);
}

// ???
int main(int argc, char const *argv[]) {
    // ??
    int N;
    scanf("%d", &N);
    point_t A[N], B[N];
    // ??
    for (size_t i = 0; i < N; i++) {
        scanf("%lf %lf", &A[i].x, &A[i].y);
    }
    for (size_t i = 0; i < N; i++) {
        scanf("%lf %lf", &B[i].x, &B[i].y);
    }
    // ??
    calcExpansionRate(N, A, B);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:61:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:65:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf %lf", &A[i].x, &A[i].y);
         ^
./Main.c:68:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf %lf", &B[i].x, &B[i].y);
         ^