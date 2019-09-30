#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b ? a:b)
#define N_max 55
#define Q_max (N_max*N_max)
int Taste[N_max][N_max];
int Taste_right[N_max][N_max];
int Taste_any[N_max][N_max][N_max][N_max];
int Area_max[Q_max] = {0};
// ??
int N;
int Q, P[Q_max];    // ?????

// ?????????????????????
int sum_right (int i, int j) {
    if (i>N || j>N) {
        return 0;
    } else if (i==N && j==N) {
        Taste_right[N][N] = Taste[N][N];
        return Taste_right[N][N];
    } else if (Taste_right[i][j] != 0) {  // ???
        return Taste_right[i][j];
    } else {
        Taste_right[i][j] = sum_right(i+1, j) + sum_right(i, j+1);
        Taste_right[i][j] -=  sum_right(i+1, j+1);
        Taste_right[i][j] += Taste[i][j];
    }
    return Taste_right[i][j];
}
// ????????????????
void calc_all_rightRectanle (int N) {
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            sum_right(i, j);
        }
    }
}
// ??????????????????
int calc_any_Rectangle (int i, int j, int v, int h) {
    int any_taste_sum = 0;
    any_taste_sum = Taste_right[i][j] - Taste_right[i+v][j] - Taste_right[i][j+h] + Taste_right[i+v][j+h];
    Taste_any[i][j][v][h] = any_taste_sum;

    return Taste_any[i][j][v][h];
}
// ?????????????????????
void calc_all_Rectangle (int N) {
    calc_all_rightRectanle(N);
    int area = 0;
    // ?????
    for (int i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            for (size_t v = 1; v <= N-i+1; v++) {
                for (size_t h = 1; h <= N-j+1; h++) {
                    area = v*h;
                    Area_max[area] = max(Area_max[area], calc_any_Rectangle(i, j, v, h));
                }
            }
        }
    }

}
// ?????????????
void recalc_total_Taste (long all_rectangle) {
    for (size_t i = 1; i <= all_rectangle; i++) {
        Area_max[i] = max(Area_max[i-1], Area_max[i]);
    }
}



int main(int argc, char const *argv[]) {
    // ???????
    scanf("%d", &N );
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            scanf("%d", &Taste[i][j] );
        }
    }
    // ?????t?????????
    scanf("%d", &Q );
    for (size_t i = 1; i <= Q; i++) {
        scanf("%d", &P[i] );
    }
    // Taste_right?0????
    memset(Taste_right, 0, sizeof(Taste_right));
    // ??
    calc_all_Rectangle(N);
    // ?????
    long all_rectangle = N*N;
    recalc_total_Taste(all_rectangle);
    // ??
    for (size_t i = 1; i <= Q; i++) {
        printf("%d\n", Area_max[P[i]] );
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:74:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^
./Main.c:77:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &Taste[i][j] );
             ^
./Main.c:81:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &Q );
     ^
./Main.c:83:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &P[i] );
         ^