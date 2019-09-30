#include <stdio.h>

int dp[1 << 20];
int dp2[1 << 20][20];

int check(int a[], int b[], int x)
{
    int i;
    
    for (i = 0; i < x; i++) {
        if (a[i] < b[i]) return 1;
        
        if (a[i] > b[i]) return 0;
    }
    
    return 0;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int k, n, j, l, r;
        int a[40];
        int b[20];
        int c[20];
        int d[20][40];
        
        scanf("%d %d", &k, &n);
        
        for (j = 0; j < k; j++) {
            scanf("%d", &a[j]);
            
            a[j]--;
        }
        
        for (j = 0; j < n; j++) {
            scanf("%d %d", &b[j], &c[j]);
            
            b[j]--;
            
            for (l = 0; l < c[j]; l++) {
                scanf("%d", &d[j][l]);
                
                d[j][l]--;
            }
        }
        
        for (j = 0; j < (1 << n); j++) dp[j] = 0;
        
        dp[0] = 1;
        
        for (j = 0; j < (1 << n); j++) {
            int x = 0;
            int p[200] = {0};
            
            if (dp[j] == 0) continue;
            
            for (l = 0; l < k; l++) p[a[l]]++;
            
            for (l = 0; l < n; l++) {
                if ((j >> l) & 1) {
                    p[b[l]]--;
                    
                    for (r = 0; r < c[l]; r++) p[d[l][r]]++;
                    
                    x++;
                }
            }
            
            for (l = 0; l < n; l++) {
                if ((j >> l) & 1) continue;
                
                if (p[b[l]] == 0) continue;
                
                if (dp[j | (1 << l)] == 0 || check(dp2[j], dp2[j | (1 << l)], x)) {
                    dp[j | (1 << l)] = 1;
                    
                    for (r = 0; r < x; r++) dp2[j | (1 << l)][r] = dp2[j][r];
                    
                    dp2[j | (1 << l)][r] = l + 1;
                }
            }
        }
        
        printf("Case #%d:", i + 1);
        
        if (dp[(1 << n) - 1] == 0) {
            puts(" IMPOSSIBLE");
        } else {
            for (j = 0; j < n; j++) printf(" %d", dp2[(1 << n) - 1][j]);
            
            puts("");
        }
    }
    
    return 0;
}
