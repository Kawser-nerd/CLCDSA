#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define n_MAX 1000
#define eps -0.00001
// ??????
double Distance (int xa, int xb, int ya, int yb) {
    double distance;
    int x = abs(xa-xb);
    int y = abs(ya-yb);
    distance = sqrt(x*x+y*y);
    return distance;
}
// ??
int Check (int n, int txa, int tya, int txb, int tyb, int X[], int Y[], int T, int V) {
    // ??
    for (size_t i = 0; i < n; i++) {
        double distance1 = Distance(txa, X[i], tya, Y[i]);
        double distance2 = Distance(X[i], txb, Y[i], tyb);
        double lim = T*V;
        if (lim >= distance1+distance2) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

int main(int argc, char const *argv[]) {
    // ??
    int txa, tya, txb, tyb, T, V;
    int n;
    int X[n_MAX], Y[n_MAX];
    // ??
    scanf("%d %d %d %d %d %d", &txa, &tya, &txb, &tyb, &T, &V);
    scanf("%d", &n );
    for (size_t i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    // ??
    Check(n, txa, tya, txb, tyb, X, Y, T, V);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d %d %d", &txa, &tya, &txb, &tyb, &T, &V);
     ^
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n );
     ^
./Main.c:40:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &X[i], &Y[i]);
         ^