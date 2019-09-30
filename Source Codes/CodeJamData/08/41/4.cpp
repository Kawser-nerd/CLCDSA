#include <stdio.h>

int data[10000], edible[10000]; /*edible = edit - able, hmm, it does not mean to be something eat-able, just edit-able*/
int n, k;
int dp[10000][2];

int main () {
    int t, i, a, b, c, d;
    int ct = 0;
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d", &n, &k);
        for (i = 0; i < n; i ++) {
            scanf("%d", data + i);
            if (i < n / 2)
                scanf("%d", edible + i);
            }
        
        for (i = n - 1; i >= n / 2; i --)
            if (data[i]) {
                dp[i][1] = 0;
                dp[i][0] = -1;
                }
            else {
                dp[i][1] = -1;
                dp[i][0] = 0;                
                }
        
        for (i = n / 2 - 1; i >= 0; i --) {
            //dp 0
            
            dp[i][0] = dp[i][1] = -1;
            for (a = (edible[i]? 0 : data[i]);a <= (edible[i]? 1 : data[i]); a ++)
                for (b = 0; b <= 1; b ++)
                    if (dp[i * 2 + 1][b] != -1)
                        for (c = 0; c <= 1; c ++)
                            if (dp[i * 2 + 2][c] != -1) {
                                d = a? (b & c) : (b | c);
                                if (dp[i][d] == -1 || dp[i][d] > dp[i * 2 + 1][b] + dp[i * 2 + 2][c] + (a != data[i]))
                                    dp[i][d] = dp[i * 2 + 1][b] + dp[i * 2 + 2][c] + (a != data[i]);
                                }
            }
        
        if (dp[0][k] == -1)
            printf("Case #%d: IMPOSSIBLE\n", ++ct);
        else
            printf("Case #%d: %d\n", ++ct, dp[0][k]);
        }
    
    return 0;
    }
