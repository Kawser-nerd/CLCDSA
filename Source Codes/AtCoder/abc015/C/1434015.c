#include <limits.h>
#include <stdio.h>

int n, k, t[6][6];

int is_dfs(int acc, int level) {
    int i, tmp, min = INT_MAX;
    
    if (level > n) return acc;
    
    for (i = 1; i <= k; ++i) {
        tmp = is_dfs(acc ^ t[level][i], level + 1);
        if (tmp < min) min = tmp;
    }
    
    return min;
}

int main(void) {
    int i, j;
    
    scanf("%d%d", &n, &k);
    
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= k; ++j) {
            scanf("%d", &t[i][j]);
        }
    }
    
    if (is_dfs(0, 1))
        printf("Nothing\n");
    else
        printf("Found\n");
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &k);
     ^
./Main.c:26:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &t[i][j]);
             ^