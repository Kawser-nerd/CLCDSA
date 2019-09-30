#include <stdio.h>

static int calc(int x1, int y1, int x2, int y2, int D[50][50]);

int main(int argc, char *argv[])
{
    int i, j, k, l, N, Q, n, val, D[50][50], v[50*50+1] = {0};
    scanf("%d", &N);

    for ( i = 0; i < N; i++ ){
        for ( j = 0; j < N; j++ ){
            scanf("%d", &D[i][j]);
        }
    }

    for ( i = 0; i < N; i++ ){
        for ( j = i; j < N; j++ ){
            for ( k = 0; k < N; k++ ){
                for ( l = k; l < N; l++ ){
                    n = (j-i+1)*(l-k+1);
                    val = calc(i, k, j, l, D);
                    if ( val > v[n] ){
                        v[n] = val;
                    }
                }
            }
        }
    }
    for ( i = 1, n = 0; i <= N*N; i++ ){
        if ( n > v[i] ){
            v[i] = n;
        } else {
            n = v[i];
        }
    }
    scanf("%d", &Q);
    for ( i = 0; i < Q; i++ ){
        scanf("%d", &n);
        printf("%d\n", v[n]);
    }

    return 0;
}

static int calc(int x1, int y1, int x2, int y2, int D[50][50])
{
    int i, j, val = 0;
    for ( i = x1; i <= x2; i++ ){
        for (j = y1; j <= y2; j++ ){
            val += D[i][j];
        }
    }
    return val;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:12:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &D[i][j]);
             ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &Q);
     ^
./Main.c:38:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &n);
         ^