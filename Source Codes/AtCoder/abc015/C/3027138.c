#include <stdio.h>

int n, k;
int t[10][10];
int has_bug(int i, int num);

int has_bug(int i, int num) {
    //printf("%d %d\n", i, num);
    if (i == n && num == 0) return 1;
    else if (i == n) return 0;
    int res = 0;
    for (int j = 0; j < k; j++) {
        res |= has_bug(i+1, num^t[i][j]);
    }
    //printf("res: %d %d\n", k, res);
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &t[i][j]);
        }
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        res |= has_bug(1, t[0][i]);
    }
    if (res) puts("Found");
    else puts("Nothing");
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &k);
     ^
./Main.c:23:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &t[i][j]);
             ^