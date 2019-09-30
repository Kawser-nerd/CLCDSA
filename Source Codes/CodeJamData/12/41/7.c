#include<stdio.h>
#include<stdlib.h>
#define MAX(x, y) ((x)>(y)?(x):(y))
#define MIN(x, y) ((x)<(y)?(x):(y))

int main(){
    int t, tt, n, d[10000], l[10000], D;
    scanf("%d", &t);
    for (tt = 1 ; tt <= t ; ++tt){
        int i, j, fl = 0, dp[10000] = {};
        scanf("%d", &n);
        for (i = 0 ; i < n ; ++i)
            scanf("%d%d", d + i, l + i);
        scanf("%d", &D);
        dp[0] = d[0];
        for (i = 0 ; i < n && dp[i] ; ++i){
            if (d[i] + dp[i] >= D){
               fl = 1;
               break;
            }
            for (j = i + 1 ; j < n && d[j] - d[i] <= dp[i] ; ++j)
                dp[j] = MAX(dp[j], MIN(l[j], d[j] - d[i]));
        }
        printf("Case #%d: %s\n", tt, fl ? "YES" : "NO");
    }
    return 0;
}
