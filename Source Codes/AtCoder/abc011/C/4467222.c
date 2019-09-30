#include <stdio.h>
#include <string.h>
#define min(a, b) (a<b ? a:b)
#define INF 100000

void Judge (int N, int NG[]) {
    int DP[310];
    // DP???
    for (size_t i = 0; i < N; i++) {
        DP[i] = INF;
    }
    DP[N] = 0;
    // ??
    for (int i = N; i >= 0; i--) {
        if (i==NG[0] || i==NG[1] || i==NG[2]) {
            continue;
        }
        for (size_t j = 1; j <= 3; j++) {
            DP[i-j] = min(DP[i]+1, DP[i-j]);
        }
    }
    if (DP[0] <= 100) {
        printf("YES\n");   // ??
    } else {
        printf("NO\n");
    }
}

int main(int argc, char const *argv[]) {
    // ??
    int N, NG[3];
    // ??
    scanf("%d", &N );
    for (size_t i = 0; i < 3; i++) {
        scanf("%d", &NG[i]);
        if (N==NG[i]) {
            printf("NO");
            return 0;
        }
    }
    // ??
    Judge(N, NG);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^
./Main.c:35:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &NG[i]);
         ^