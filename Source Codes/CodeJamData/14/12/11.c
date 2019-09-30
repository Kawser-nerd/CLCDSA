#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

bool visited[1010];
int temp_len[1010], temp_ar[1010][1010];
int t, n, len[1010], ar[1010][1010], dp[1010];

void dfs(int i, int p){
    visited[i] = true;

    int j, x;
    for (j = 0; j < temp_len[i]; j++){
        x = temp_ar[i][j];
        if (x != p){
            dfs(x, i);
            ar[i][len[i]++] = x;
        }
    }
}

int F(int i){
    if (visited[i]) return dp[i];

    int j, k, x, res = 0;
    for (j = 0; j < len[i]; j++){
        for (k = j + 1; k < len[i]; k++){
            x = F(ar[i][j]) + F(ar[i][k]);
            if (x > res) res = x;
        }
    }
    res++;

    visited[i] = true;
    return (dp[i] = res);
}

int main(){
    int T = 0, i, j, k, a, b, r, x, bitmask;

    scanf("%d", &t);
    while (t--){
        clr(temp_len);
        scanf("%d", &n);
        for (i = 1; i < n; i++){
            scanf("%d %d", &a, &b);
            temp_ar[a][temp_len[a]++] = b;
            temp_ar[b][temp_len[b]++] = a;
        }

        int res = 0;
        for (i = 1; i <= n; i++){
            clr(len);
            dfs(i, i);
            clr(visited);

            for (j = 0; j < len[i]; j++){
                for (k = j + 1; k < len[i]; k++){
                    x = F(ar[i][j]) + F(ar[i][k]);
                    if (x > res) res = x;
                }
            }
        }
        res++;

        printf("Case #%d: %d\n", ++T, n - res);
    }
    return 0;
}
