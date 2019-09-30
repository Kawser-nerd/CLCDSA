#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

bool visited[1 << 17];
int t, n, lim, dp[1 << 17];
char first[1010][25], second[1010][25];

int F(int mask){
    if (mask == lim) return 0;
    if (visited[mask]) return dp[mask];

    int i, j, x, y, z, res = 0;
    for (i = 0; i < n; i++){
        if (!(mask & (1 << i))){
            x = 0, y = 0;
            for (j = 0; j < n; j++){
                if (mask & (1 << j)){
                    if (strcmp(first[i], first[j]) == 0) x++;
                    if (strcmp(second[i], second[j]) == 0) y++;
                }
            }
            z = F(mask | (1 << i)) + ((x > 0) && (y > 0));
            if (z > res) res = z;
        }
    }

    visited[mask] = true;
    return (dp[mask] = res);
}

int main(){
    read();
    write();
    int T = 0, i, j, k, x, res;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%s %s", first[i], second[i]);

        clr(visited);
        lim = (1 << n) - 1;
        printf("Case #%d: %d\n", ++T, F(0));
    }
    return 0;
}
