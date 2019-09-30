#include <stdio.h>
#define maxn 2000

int data[maxn][maxn], dp[maxn], cn[maxn];
int malt[maxn];
int cover[maxn][maxn], cp[maxn];
int n, m;

int mark (int x) {
    if (cp[x] == -1)
        return 0;
    
    int target[cp[x]], tp;
    
    tp = cp[x];
    for (int i = 0; i < cp[x]; i ++)
        target[i] = cover[x][i];
    cp[x] = -1;
    
    for (int i = 0; i < tp; i ++) {
        cn[target[i]] --;
        if (cn[target[i]] == 0) {
            if (malt[target[i]] == -1)
                return 1;
            else
                mark(malt[target[i]]);
            }
        }
    
    return 0;
    }

int main () {
    int t, i, j, k, a, b, f, ct;
    
    ct = 0;
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d", &n, &m);
        
        for (i = 0; i < m; i ++) {
            scanf("%d", &k);

            malt[i] = -1;
            dp[i] = 0;
            for (j = 0; j < k; j ++) {
                scanf("%d%d", &a, &b);
                a --;
                if (b) 
                    malt[i] = a;
                else
                    data[i][dp[i] ++] = a;
                }
            cn[i] = dp[i];
            }
        
        for (i = 0; i < n; i ++)
            cp[i] = 0;
        
        f = 1;
        for (i = 0; i < m; i ++) {
            for (j = 0; j < dp[i]; j ++)
                if (cp[data[i][j]] == -1)
                    cn[i] --;
            if (cn[i] == 0) {
                if (malt[i] == -1) {
                    f = 0;
                    break;
                    }
                else
                    if (mark(malt[i])) {
                        f = 0;
                        break;
                        }
                }
            else {
                for (j = 0; j < dp[i]; j ++)
                    if (cp[data[i][j]] != -1)
                        cover[data[i][j]][cp[data[i][j]] ++] = i;
                }
            }
        
        if (f) {
            printf("Case #%d:", ++ ct);
            for (i = 0; i < n; i ++)
                printf(" %d", cp[i] == -1);
            printf("\n");
            }
        else
            printf("Case #%d: IMPOSSIBLE\n", ++ ct);
        }
    
    return 0;    
    }
