#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

bool visited[1 << 20], dp[1 << 20];
int t, k, n, lim, ye, yo[25], len[1010], lol[25][1010], keys[25], next[1 << 20], index[1 << 20];

bool F(int bitmask, int ar[205]){
    if (bitmask == lim) return true;
    if (visited[bitmask]) return dp[bitmask];

    int i, j;
    bool res = false;
    for (i = 0; i < n; i++){
        if (!(bitmask & (1 << i)) && ar[keys[i]]){
            ar[keys[i]]--;
            for (j = 0; j < len[i]; j++){
                int x = lol[i][j];
                ar[x]++;
            }

            bool flag = F(bitmask | (1 << i), ar);

            ar[keys[i]]++;
            for (j = 0; j < len[i]; j++){
                int x = lol[i][j];
                ar[x]--;
            }

            if (flag){
                res = true;
                index[bitmask] = i;
                next[bitmask] = bitmask | (1 << i);
                break;
            }
        }
    }

    visited[bitmask] = true;
    return (dp[bitmask] = res);
}

void backtrack(int bitmask){
    if (bitmask == lim) return;
    yo[ye++] = index[bitmask];
    backtrack(next[bitmask]);
}

int main(){
    int line, i, j, x, ar[205];

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        clr(len), clr(ar);

        scanf("%d %d", &k, &n);
        lim = (1 << n) - 1;
        for (i = 0; i < k; i++){
            scanf("%d", &x);
            ar[x]++;
        }

        for (i = 0; i < n; i++){
            scanf("%d", &keys[i]);

            scanf("%d", &len[i]);
            for (j = 0; j < len[i]; j++){
                scanf("%d", &lol[i][j]);
            }
        }

        clr(visited);
        bool res = F(0, ar);
        printf("Case #%d:", line);
        if (!res) puts(" IMPOSSIBLE");
        else{
            ye = 0;
            backtrack(0);
            for (i = 0; i < n; i++) printf(" %d", yo[i] + 1);
            puts("");
        }
    }
    return 0;
}
