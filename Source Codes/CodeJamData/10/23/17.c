#include <stdio.h>
#include <string.h>
int M;
int n;
int cnt;
int path[1000];
int dp[1000];
void dfs(int u, int idx)
{
    int temp, i;
    if (u == n-1) {
        path[idx] = n;
        temp = idx;
        while (temp != 1) {
            for (i = 1; i <= idx; i++) {
                if (path[i] == temp) {
                    break;
                }
            }
            if (i == idx+1)
                return ;
            temp = i;
        }
        cnt++;
        return ;
    }
    dfs(u+1, idx);
    path[idx] = u+1;
    dfs(u+1, idx+1);
}
int main()
{
    int tc, cn;
    int i, j, k;
    M = 100003;
    n = 25;
    dp[2] = 1;
    for (n = 3; n <= 25; n++) {
        cnt = 0;
        dfs(2, 1);
        path[1] = 2;
        dfs(2, 2);
        cnt %= M;
        dp[n] = cnt;
    }
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", cn, dp[n]);
    }
    return 0;
}
