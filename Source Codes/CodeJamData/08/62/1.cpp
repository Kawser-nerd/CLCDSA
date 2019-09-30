#include <stdio.h>

int data[50][50], dmg[50][50];
int x, y, xx, yy;
int best;

void dfs (int steps) {
    
/*
    printf("dfs %d\n", steps);
    for (int i = 0; i < x; i ++) {
        for (int j = 0; j < y; j ++)
            printf("%4d", data[i][j]);
        printf("\n");
        }
    printf("\n");
    fflush(stdout);
*/
    
    if (data[xx][yy] == 0)
        return;
    
    int f = 1;
    if (xx - 1 >= 0 && data[xx-1][yy] > 0) f = 0;
    if (xx + 1 < x && data[xx+1][yy] > 0) f = 0;
    if (yy - 1 >= 0 && data[xx][yy-1] > 0) f = 0;
    if (yy + 1 < y && data[xx][yy+1] > 0) f = 0;
    
    if (f) {
        best = 2147483647;
        return;
        }
    
    if (best == 2147483647)
        return;
    
    best >?= steps;
    
    int prev[50][50];
    
    for (int i = 0; i < x; i ++)
        for (int j = 0; j < y; j ++) {
            prev[i][j] = data[i][j];
            dmg[i][j] = 0;
            }

    for (int i = 0; i < x; i ++)
        for (int j = 0; j < y; j ++)
            if (i != xx || j != yy) {
                int bx = -1, by;
                
                for (int k = (i == 0? 0 : -1); k <= (i == x - 1 ? 0 : 1); k ++)
                    for (int l = (j == 0? 0 : -1); l <= (j == y - 1? 0 : 1); l ++)
                        if ((k!=0)^(l!=0) && (bx == -1 || data[i + k][j + l] > data[bx][by])) {
                            bx = i + k;
                            by = j + l;
                            }
//                printf("i j bx by %d %d %d %d\n",i, j,bx,by);
                dmg[bx][by] += data[i][j];
                }
    int sp = prev[xx][yy];
    for (int i = 0; i < x; i ++)
        for (int j = 0; j < y; j ++)
            prev[i][j] -= dmg[i][j];
    
    if (xx - 1 >= 0 && prev[xx - 1][yy] > 0) {
            for (int i = 0; i < x; i ++)
                for (int j = 0; j < y; j ++) {
                    data[i][j] = prev[i][j];
                    if (i == xx - 1 && j == yy)
                        data[i][j] -= sp;
                    if (data[i][j] < 0)
                        data[i][j] = 0;
                    }
            dfs(steps + 1);
        }
    if (xx + 1 < x && prev[xx + 1][yy] > 0) {
            for (int i = 0; i < x; i ++)
                for (int j = 0; j < y; j ++) {
                    data[i][j] = prev[i][j];
                    if (i == xx + 1 && j == yy)
                        data[i][j] -= sp;
                    if (data[i][j] < 0)
                        data[i][j] = 0;
                    }
            dfs(steps + 1);
        }
    if (yy - 1 >= 0 && prev[xx][yy - 1] > 0) {
            for (int i = 0; i < x; i ++)
                for (int j = 0; j < y; j ++) {
                    data[i][j] = prev[i][j];
                    if (i == xx && j == yy - 1)
                        data[i][j] -= sp;
                    if (data[i][j] < 0)
                        data[i][j] = 0;
                    }
            dfs(steps + 1);
        }
    if (yy + 1 < y && prev[xx][yy + 1] > 0) {
            for (int i = 0; i < x; i ++)
                for (int j = 0; j < y; j ++) {
                    data[i][j] = prev[i][j];
                    if (i == xx && j == yy + 1)
                        data[i][j] -= sp;
                    if (data[i][j] < 0)
                        data[i][j] = 0;
                    }
            dfs(steps + 1);
        }
            
    for (int i = 0; i < x; i ++)
        for (int j = 0; j < y; j ++) {
            data[i][j] = prev[i][j];
            if (data[i][j] < 0)
                data[i][j] = 0;
            }
    dfs(steps + 1);
    }

int main () {
    int t, ct = 0;
    
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d%d%d", &y, &x, &yy, &xx);
        xx --;
        yy --;
        for (int i = 0; i < x; i ++)
            for (int j = 0; j < y; j ++)
                scanf("%d", data[i] + j);
        best = 0;
        dfs(0);
        if (best == 2147483647)
            printf("Case #%d: forever\n", ++ ct);
        else
            printf("Case #%d: %d day(s)\n", ++ ct, best);
        }
    
    return 0;
    }
