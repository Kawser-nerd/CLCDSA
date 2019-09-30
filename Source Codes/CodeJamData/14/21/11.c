#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define inf (1 << 25)
#define min(a,b) ((a)<(b)?(a):(b))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

bool visited[105][105];
char str[105], str2[105];
int n, m, r, dp[105][105];

int F(int i, int j){
    if (i > n || j > m) return inf;
    if (i == n && j == m) return 0;
    if (visited[i][j]) return dp[i][j];

    int res = inf;
    if (str[i] == str2[j]) res = min(res, F(i + 1, j + 1));
    if ((i + 1) != n && str[i] == str[i + 1]) res = min(res, 1 + F(i + 1, j));
    if ((j + 1) != m && str2[j] == str2[j + 1]) res = min(res, 1 + F(i, j + 1));

    visited[i][j] = true;
    return (dp[i][j] = res);
}

int main(){
    read();
    write();
    int T = 0, t, i, j;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &r);
        scanf("%s %s", str, str2);
        n = strlen(str), m = strlen(str2);

        clr(visited);
        int res = F(0, 0);
        if (res >= inf) printf("Case #%d: Fegla Won\n", ++T);
        else printf("Case #%d: %d\n", ++T, res);
    }
    return 0;
}
