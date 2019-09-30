#include <stdio.h>
#define sizeN 11
#define INF 10000
#define min(a, b) (a<b ? a:b)
int Friend[sizeN][sizeN];
// ???
void InitFriend() {
    for (size_t i = 0; i < sizeN; i++) {
        for (size_t j = 0; j < sizeN; j++) {
            if (i == j) {
                Friend[i][j] = 0;
            } else {
                Friend[i][j] = INF;
            }
        }
    }
}
// ??????????
void WFmethod (int N) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            for (size_t k = 0; k < N; k++) {
                Friend[i][j] = min(Friend[i][j], Friend[i][k]+Friend[k][j]);
            }
        }
    }
    // ??
    for (size_t i = 0; i < N; i++) {
        int cnt = 0;
        for (size_t j = 0; j < N; j++) {
            if (Friend[i][j] == 2) {
                cnt ++;
            }
        }
        printf("%d\n", cnt);
    }
}

int main(int argc, char const *argv[]) {
    // ??
    int N, M;
    // ??
    scanf("%d %d", &N, &M);
    int a, b;
    InitFriend();
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        // ?????????
        Friend[a][b] = 1;
        Friend[b][a] = Friend[a][b];
    }
    // ?????????
    WFmethod(N);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:43:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:47:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a, &b);
         ^