#include <stdio.h>
#include <string.h>

int n, m;
int data[80][80];
int n1, n2;
int d[3200][6], dp[3200];
int op[3200], used[3200];

int dfs (int x) {
    used[x] = 1;
    for (int i = 0; i < dp[x]; i ++)
        if (op[d[x][i]] == -1) {
            op[d[x][i]] = x;
            return 1;
            }
    for (int i = 0; i < dp[x]; i ++)
        if (!used[op[d[x][i]]] && dfs(op[d[x][i]])) {
            op[d[x][i]] = x;
            return 1;
            }
    return 0;
    }

int main () {
    int t, i, j, ct = 0;
    char ch;
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d", &n, &m);
        
        n1 = n2 = 0;
        for (i = 0; i < n; i ++)
            for (j = 0; j < m; j ++) {
                do scanf("%c", &ch);
                    while (ch <= ' ');
                data[i][j] = ch == '.'? ((j & 1)? n2 ++ : n1 ++) : -1;
                }

        for (i = 0; i < n; i ++)
            for (j = 0; j < m; j += 2)
                if (data[i][j] != -1) {
                    
                    dp[data[i][j]] = 0;
                    if (j - 1 >= 0) {
                        if (i - 1 >= 0 && data[i - 1][j - 1] != -1)
                            d[data[i][j]][dp[data[i][j]]++] = data[i-1][j-1];
                        if (data[i][j - 1] != -1)
                            d[data[i][j]][dp[data[i][j]]++] = data[i][j-1];
                        if (i + 1 < n && data[i + 1][j - 1] != -1)
                            d[data[i][j]][dp[data[i][j]]++] = data[i+1][j-1];
                        }
                    if (j + 1 < m) {
                        if (i - 1 >= 0 && data[i - 1][j + 1] != -1)
                            d[data[i][j]][dp[data[i][j]]++] = data[i-1][j+1];
                        if (data[i][j + 1] != -1)
                            d[data[i][j]][dp[data[i][j]]++] = data[i][j+1];
                        if (i + 1 < n && data[i + 1][j + 1] != -1)
                            d[data[i][j]][dp[data[i][j]]++] = data[i+1][j+1];
                        }
                    }
        
        memset(op, -1, sizeof(op));
/*
        for (i = 0; i < n; i ++) {
            for (j = 0; j < m; j ++)
                printf("%d ",data[i][j]);
            printf("\n");
            }
        for (i = 0; i < n1; i ++) {
            printf("%d: ",i);
            for (j = 0; j < dp[i]; j ++)
                printf("%d,",d[i][j]);
            printf("\n");
            }
*/
        j = 0;
        for (i = 0; i < n1; i ++) {
            memset(used, 0, sizeof(used));
            j += dfs(i);
            }
        
        printf("Case #%d: %d\n", ++ct, n1 + n2 - j);
        }
    
    return 0;
    }
