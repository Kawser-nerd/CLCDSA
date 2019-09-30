#include <stdio.h>
#include <string.h>

int n, m;
int ind[100], next[200], to[200], p;
int ind2[100], next2[200], to2[200], p2;
int deg[100], deg2[100];

int dp[100][100];
int conn[100][100], l, r;
int op[100], used[100];

int dfsx (int x) {
//    printf("dfsx\n");
    used[x] = 1;
    for (int i = 0; i < r; i ++)
        if (conn[x][i] && op[i] == -1) {
            op[i] = x;
            return 1;
            }
    for (int i = 0; i < r; i ++)
        if (conn[x][i] && !used[op[i]] && dfsx(op[i])) {
            op[i] = x;
            return 1;
            }
    return 0;
    }

int match () {
    for (int i = 0; i < r; i ++)
        op[i] = -1;
    for (int i = 0; i < l; i ++) {
        for (int j = 0; j < l; j ++)
            used[j] = 0;
        if (!dfsx(i))
            return 0;
        }
    return 1;
    }

void dfs (int a, int ad, int b, int bd) {

//    printf("dfs %d, %d\n", a, b);
    
    if (deg[a] < deg2[b])
        dp[a][b] = 0;
    if (dp[a][b] != -1)
        return;
        
    dp[a][b] = 0;
    
    int ac[100], ap, bc[100], bp;
    
    ap = bp = 0;
    for (int i = ind[a]; i != -1; i = next[i])
        if (to[i] != ad)
            ac[ap ++] = to[i];
    for (int i = ind2[b]; i != -1; i = next2[i])
        if (to2[i] != bd)
            bc[bp ++] = to2[i];
    
    for (int i = 0; i < ap; i ++)
        for (int j = 0; j < bp; j ++)
            dfs(ac[i], a, bc[j], b);
    
    l = bp;
    r = ap;
    for (int j = 0; j < bp; j ++)
        for (int i = 0; i < ap; i ++)
            conn[j][i] = dp[ac[i]][bc[j]];

/*
    for (int j = 0; j < bp; j ++) {
        for (int i = 0; i < ap; i ++)
            printf("%d", conn[j][i]);
        printf("\n");
        }
*/

    dp[a][b] = match();
    }

int test (int x) {
    memset(dp, -1, sizeof(dp));
    dfs(x, -1, 0, -1);
    
    return dp[x][0];
    }

int main () {
    int t, ct = 0;
    
    freopen("4.in", "r", stdin);
    freopen("4.out", "w", stdout);
    
    for (scanf("%d", &t); t > 0; t --) {
        
        memset(ind, -1, sizeof(ind));
        memset(ind2, -1, sizeof(ind2));
        memset(deg, 0, sizeof(deg));
        memset(deg2, 0, sizeof(deg2));
        p = p2 = 0;
        
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i ++) {
            int a, b;
            
            scanf("%d%d", &a, &b);
            a --;
            b --;
            
            deg[a] ++;
            deg[b] ++;
            
            next[p] = ind[a];
            to[p] = b;
            ind[a] = p ++;
            
            next[p] = ind[b];
            to[p] = a;
            ind[b] = p ++;
            }

        scanf("%d", &m);
        for (int i = 0; i < m - 1; i ++) {
            int a, b;
            
            scanf("%d%d", &a, &b);
            a --;
            b --;
            
            deg2[a] ++;
            deg2[b] ++;
            
            next2[p2] = ind2[a];
            to2[p2] = b;
            ind2[a] = p2 ++;
            
            next2[p2] = ind2[b];
            to2[p2] = a;
            ind2[b] = p2 ++;
            }
        
        int f = 0;
        for (int i = 0; i < n && !f; i ++)
            if (test(i))
                f = 1;
        
        if (f)
            printf("Case #%d: YES\n", ++ct);
        else
            printf("Case #%d: NO\n", ++ct);
        }

    return 0;
    }
