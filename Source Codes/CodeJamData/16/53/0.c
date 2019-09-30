#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

double dis[MAX][MAX];
char visited[MAX], adj[MAX][MAX];
int t, n, s, X[MAX], Y[MAX], Z[MAX], VX[MAX], VY[MAX], VZ[MAX];

bool dfs(int i){
    int j;
    visited[i] = 1;
    for (j = 0; j < n; j++){
        if (adj[i][j] && !visited[j]) dfs(j);
    }
}

bool check(double lim){
    clr(adj);
    int i, j, k;
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (lim > dis[i][j]) adj[i][j] = adj[j][i] = 1;
        }
    }

    clr(visited);
    dfs(0);
    return visited[1];
}

int main(){
    read();
    write();
    int T = 0, i, j, k, l;
    double x, y, z, d, low, high, mid, res;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &s);
        for (i = 0; i < n; i++) scanf("%d %d %d %d %d %d", &X[i], &Y[i], &Z[i], &VX[i], &VY[i], &VZ[i]);

        for (i = 0; i < n; i++){
            for (j = i + 1; j < n; j++){
                x = (X[i] - X[j]), y = (Y[i] - Y[j]), z = (Z[i] - Z[j]);
                d = sqrt(x * x + y * y + z * z);
                dis[i][j] = dis[j][i] = d;
            }
            dis[i][i] = 0.0;
        }

        low = 0.0, high = 1e9;
        for (i = 0; i < 237; i++){
            mid = (low + high) / 2.0;
            if (check(mid)) high = mid;
            else low = mid;
        }

        printf("Case #%d: %0.12f\n", ++T, low + 1e-15);
    }
    return 0;
}
