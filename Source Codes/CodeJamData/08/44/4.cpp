#include <stdio.h>
#include <string.h>

int k, n;
char str[60000];
int p1[16][16];
int p2[16][16];
int beg;
int dp[65536][16];

void ask (int a, int b) {
    if (a == (1 << beg))
        dp[a][b] = 0;
    else {
        int aa = a - (1 << b);
        dp[a][b] = 0;
        for (int i = 0; i < k; i ++)
            if ((aa & (1 << i)) && (aa == (1 << i) || i != beg)) {
                if (dp[aa][i] == -1)
                    ask(aa, i);
                dp[a][b] >?= dp[aa][i] + p1[i][b];
                }
        }
    }

int main () {
    int t, i, a, b, ct;
    
    ct = 0;
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%s", &k, str);
        
        for (a = 0; a < k; a ++)
            for (b = 0; b < k; b ++)
                p1[a][b] = p2[a][b] = 0;
        
        n = strlen(str);
        for (i = 0; i < n; i += k)
            for (a = 0; a < k; a ++)
                for (b = 0; b < k; b ++) {
                    p1[a][b] += (str[a + i] == str[b + i]);
                    if (i + k < n)
                        p2[a][b] += (str[a + i] == str[b + i + k]);
                    }

        b = 0;
        for (i = 0; i < k; i ++) {
            beg = i;
            memset(dp, -1, sizeof(dp));
            for (a = 0; a < k; a ++)
                if (i != a) {
                    ask((1 << k) - 1, a);
                    b >?= dp[(1 << k) - 1][a] + p2[a][i];
                    }
            }
        printf("Case #%d: %d\n", ++ct, n - b);
        }
    
    return 0;
    }
