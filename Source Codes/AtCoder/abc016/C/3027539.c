#include <stdio.h>

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int friend[12][12] = {0};
    int sfriend[12][12] = {0};
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        friend[a-1][b-1] = 1;
        friend[b-1][a-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (friend[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (friend[j][k]) sfriend[i][k] = 1;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (friend[i][j] || i == j) sfriend[i][j] = 0;
            cnt += sfriend[i][j];
        }
        printf("%d\n", cnt);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &m);
     ^
./Main.c:10:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         int a, b; scanf("%d%d", &a, &b);
                   ^