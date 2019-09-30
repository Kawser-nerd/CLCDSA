#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double combi[1001][1001];
// ??????????????
void Combi (int n) {
    // ????
    combi[0][0] = 1;
    // ????????
    for (int i = 1; i <= n; i++) {
        for (int  j = 0; j <= i; j++) {
            if (j-1 >= 0) {
                combi[i][j] = (combi[i-1][j-1]+combi[i-1][j])/2;
            } else {
                combi[i][j] = combi[i-1][j]/2;
            }
        }
    }
}

// ??????
double getNumOfCombination (int N, int nx, int ny, int horizon) {
    int vertical = N-horizon;
    if ((horizon+nx)%2 != 0) { return 0; }
    if ((vertical+ny)%2 != 0) { return 0; }
    int right = (horizon+nx)/2;
    int up = (vertical+ny)/2;
    if (right<0 || up<0) { return 0;}
    // ??
    Combi(N);
    double p = 0;
    p = combi[N][horizon]*combi[horizon][right]*combi[vertical][up];
    return p;
}

// ??????
double Jump (int N, int D, int X, int Y) {
    double probability = 0;
    if (X%D!=0 || Y%D!=0) {
        return 0;
    }
    int nx = X/D;
    int ny = Y/D;
    for (int horizon = 0; horizon <= N; horizon++) {
        probability += getNumOfCombination(N, nx, ny, horizon);
    }
    return probability;
}

int main(int argc, char const *argv[]) {
    // ??
    int N, D;
    int X, Y;
    // ??
    scanf("%d %d", &N, &D );
    scanf("%d %d", &X, &Y );
    // ??
    double ans = Jump(N, D, X, Y);
    printf("%lf\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:55:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &D );
     ^
./Main.c:56:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &X, &Y );
     ^