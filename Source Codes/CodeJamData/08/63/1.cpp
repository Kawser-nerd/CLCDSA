#include <stdio.h>

int m;
double p, s;
double dp[100000], prev[100000];

int main () {
    int t, ct = 0;
    
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%lf%lf", &m, &p, &s);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j <= (1 << i); j ++)
                prev[j] = dp[j];
            for (int j = 0; j <= (1 << (i + 1)); j ++) {
                dp[j] = 0;
                for (int k = j / 2; k >= 0 && j - k <= (1 << i); k --)
                    dp[j] >?= p * prev[j - k] + (1 - p) * prev[k];
                }
            }
        
        printf("Case #%d: %.10lf\n", ++ct, dp[(int)(s / 1000000.0 * (1 << m) + 1e-11)]);
        }
    
    return 0;
    }
