#include <stdio.h>
#define size 5
#define True 1
int T[size][size];
int flag;
// ?????? numQ ?????
void DFS (int N, int K, int numQ, int value) {
    if (numQ == N) {
        if (value == 0) {
            flag = True;    // ????
        } else {
        }
        return;
    }
    // ??
    for (size_t k = 0; k < K; k++) {
        DFS(N, K, numQ+1, value^T[numQ][k]);
    }
}

int main(int argc, char const *argv[]) {
    // ?? N ???
    int N, K;
    // ??
    scanf("%d %d", &N, &K);
    for (size_t n = 0; n < N; n++) {
        for (size_t k = 0; k < K; k++) {
            scanf("%d", &T[n][k]);
        }
    }
    // ??????
    DFS(N, K, 0, 0);
    // ??
    if (flag == True) {
        printf("Found\n");
    } else {
        printf("Nothing\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &K);
     ^
./Main.c:28:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &T[n][k]);
             ^