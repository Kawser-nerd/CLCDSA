#include <stdio.h>

const int N = 1000;

int n;
int dp[11][N];
int list[10], lp = 0;

int dfs (int x)
{
    if (x < N && dp[n][x] != -1)
        return dp[n][x];

    int re = 0;
    if (x < N)
        dp[n][x] = re;
    int sum = 0;
    for (int y = x; y; y /= n)
        sum += (y % n) * (y % n);
    re = dfs(sum);
    if (x < N)
        dp[n][x] = re;
    return re;
}

bool check (int x)
{
    for (int i = lp - 1; i >= 0; i --)
    {
        n = list[i];
        if (!dfs(x))
            return false;
    }
    return true;
}

void ml ()
{
    for (int i = 1; i < N; i ++)
        dp[n][i] = -1;
    dp[n][1] = 1;
    for (int i = 2; i < N; i ++)
        if (dp[n][i] == -1)
            dfs ( i );
}

int main ()
{
    int t, ct = 0;
    
    for (n = 2; n <= 10; n ++)
        ml();
    
    for (scanf("%d", &t); t > 0; t --)
    {
        int tmp;
        char ch = 'x';
        
        lp = 0;
        
        while (ch != '\n' && scanf("%d%c", &tmp, &ch) > 0)
            list[lp ++] = tmp;
        
        int res = 2;
        while (!check(res))
            res ++;
        printf("Case #%d: %d\n", ++ct, res);
    }
    
    return 0;
}
