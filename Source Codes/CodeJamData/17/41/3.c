#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 105
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

int p;
char dp[MAX][MAX][MAX][MAX][4];

int F(int n, int ar[4], int left){
    if (n == 0) return 0;
    if (dp[ar[0]][ar[1]][ar[2]][ar[3]][left] != -1) return dp[ar[0]][ar[1]][ar[2]][ar[3]][left];

    int i, j, x, y, c, res = 0;
    for (i = 0; i < p; i++){
        if (ar[i] > 0){
            ar[i]--;
            if (left >= i){
                x = F(n - 1, ar, left - i);
                if (x > res) res = x;
            }
            else{
                x = F(n - 1, ar, p - (i - left));
                if (x > res) res = x;
            }
            ar[i]++;
        }
    }
    if (left == 0) res++;

    return (dp[ar[0]][ar[1]][ar[2]][ar[3]][left] = res);
}

int main(){
    read();
    write();
    int T = 0, t, n, i, j, x, res, ar[4];

    scanf("%d", &t);
    while (t--){
        clr(ar);
        scanf("%d %d", &n, &p);
        for (i = 0; i < n; i++){
            scanf("%d", &x);
            ar[x % p]++;
        }

        memset(dp, -1, sizeof(dp));
        res = F(n, ar, 0);
        printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}
