#include <stdio.h>
#define size_M 44850
#define INF 1000000
#define min(a, b) (a<b ? a:b)
#define max(a, b) (a>b ? a:b)
// ??????????
int WarshallFloyd (int N, int M, int a[], int b[], int t[]) {
    int maxTime = INF;    // ??????????
    int distanse[N+2][N+2]; // ???? !???
    // ?????????
    for (size_t i = 0; i <= N+1; i++) {
        for (size_t j = 0; j <= N+1; j++) {
            if (i == j) {
                distanse[i][j] = 0;
            } else {
                distanse[i][j] = INF;
            }
        }
    }
    // ??????? M=????
    for (size_t i = 0; i < M; i++) {
        distanse[a[i]][b[i]] = t[i];
        distanse[b[i]][a[i]] = t[i];
    }
    // ????????
    for (size_t k = 1; k <= N; k++) {
        for (size_t i = 1; i <= N; i++) {
            for (size_t j = 1; j <= N; j++) {
                distanse[i][j] = min(distanse[i][j], distanse[i][k]+distanse[k][j]);
            }
        }
    }
    // ??????????
    for (size_t i = 1; i <= N; i++) {
        int row_max = 0;
        for (size_t j = 1; j <= N; j++) {
            // ???????????
            row_max = max(row_max, distanse[i][j]);
        }
        maxTime = min(maxTime, row_max);
    }
    return maxTime;
}

int main(int argc, char const *argv[]) {
    // ??
    int N, M;
    int a[size_M], b[size_M], t[size_M];
    // ??
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d %d", &a[i], &b[i], &t[i]);
    }
    // ??
    int ans = WarshallFloyd(N, M, a, b, t);
    printf("%d\n", ans );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:52:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &a[i], &b[i], &t[i]);
         ^