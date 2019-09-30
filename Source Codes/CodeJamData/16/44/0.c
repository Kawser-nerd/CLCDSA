#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

char str[30];
int visited[16][16], dp[16][16];
int t, n, id = 0, lim = 0, ar[4][4], cur[4][4];

int F(int i, int a, int b){
    if (i == n) return 1;
    if (visited[a][b] == id) return dp[a][b];

    int j, k, x, res = 1, counter = 0;
    for (j = 0; j < n && res == 1; j++){
        if (!(a & (1 << j))){
            for (k = 0; k < n; k++){
                if (cur[j][k] && !(b & (1 << k))){
                    if (!F(i + 1, a | (1 << j), b | (1 << k))){
                        res = 0;
                        break;
                    }
                    counter++;
                }
            }
        }
    }
    if (!counter) res = 0;

    visited[a][b] = id;
    return (dp[a][b] = res);
}

int main(){
    read();
    write();
    int T = 0, i, j, k, c, x, y, res, mask;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i = 0; i < n; i++){
            scanf("%s", str);
            for (j = 0; j < n; j++){
                ar[i][j] = str[j] - 48;
            }
        }

        res = 1010, lim = (1 << (n * n)) - 1;
        for (c = 0; c <= (n * n) && res == 1010; c++){
            for (mask = 0; mask <= lim; mask++){
                if (__builtin_popcount(mask) == c){

                    for (i = 0, k = 0; i < n; i++){
                        for (j = 0; j < n; j++, k++){
                            cur[i][j] = ar[i][j];
                            if (mask & (1 << k)) cur[i][j] = 1;
                        }
                    }

                    id++;
                    if (F(0, 0, 0)){
                        res = c;
                        break;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}
