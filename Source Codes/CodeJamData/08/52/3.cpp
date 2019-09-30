#include <stdio.h>
#include <set>
#include <string.h>
#define maxq 11390625

char data[15][15];
int n, m;

int used[15][15][15][15][15][15];

int qx[maxq], qy[maxq], ix[maxq], iy[maxq], ox[maxq], oy[maxq], qp;
int qx2[maxq], qy2[maxq], ix2[maxq], iy2[maxq], ox2[maxq], oy2[maxq], qp2;

int sx, sy, ex, ey;

int left (int x, int y) {
    while (y - 1 >= 0 && data[x][y - 1] == '.')
        y --;
    return y;
    }

int right (int x, int y) {
    while (y + 1 < m && data[x][y + 1] == '.')
        y ++;
    return y;
    }

int up (int x, int y) {
    while (x - 1 >= 0 && data[x - 1][y] == '.')
        x --;
    return x;
    }

int down (int x, int y) {
    while (x + 1 < n && data[x + 1][y] == '.')
        x ++;
    return x;
    }

void add1 (int a, int b, int c, int d, int e, int f) {
    if (used[a][b][c][d][e][f])
        return;
    
    used[a][b][c][d][e][f] = 1;
    qx[qp] = a;
    qy[qp] = b;
    ix[qp] = c;
    iy[qp] = d;
    ox[qp] = e;
    oy[qp] = f;
    qp ++;
    }

void add2 (int a, int b, int c, int d, int e, int f) {
    if (used[a][b][c][d][e][f])
        return;
    
    used[a][b][c][d][e][f] = 1;
    qx2[qp2] = a;
    qy2[qp2] = b;
    ix2[qp2] = c;
    iy2[qp2] = d;
    ox2[qp2] = e;
    oy2[qp2] = f;
    qp2 ++;
    }

int main () {
    int t, i, j, f, ct = 0, c;
    
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i ++)
            for (j = 0; j < m; j ++) {
                do scanf("%c", data[i] + j);
                    while (data[i][j] <= ' ');
                if (data[i][j] == 'O') {
                    data[i][j] = '.';
                    sx = i;
                    sy = j;
                    }
                if (data[i][j] == 'X') {
                    data[i][j] = '.';
                    ex = i;
                    ey = j;
                    }
                }
        
        memset(used, 0, sizeof(used));
        qp = 1;
        
        qx[0] = sx;
        qy[0] = sy;
        ix[0] = sx;
        iy[0] = left(sx, sy);
        ox[0] = sx;
        oy[0] = left(sx, sy);
        
        used[sx][sy][sx][left(sx,sy)][sx][left(sx,sy)] = 1;
        
        f = -1;
        c = 0;
        while (f == -1 && qp) {
            for (i = 0; i < qp && f == -1; i ++) {
                if (qx[i] == ex && qy[i] == ey)
                    f = c;
                add1(qx[i], qy[i], ix[i], iy[i], qx[i], left(qx[i], qy[i]));
                add1(qx[i], qy[i], ix[i], iy[i], qx[i], right(qx[i], qy[i]));
                add1(qx[i], qy[i], ix[i], iy[i], up(qx[i], qy[i]), qy[i]);
                add1(qx[i], qy[i], ix[i], iy[i], down(qx[i], qy[i]), qy[i]);
                add1(qx[i], qy[i], qx[i], left(qx[i], qy[i]), ox[i], oy[i]);
                add1(qx[i], qy[i], qx[i], right(qx[i], qy[i]), ox[i], oy[i]);
                add1(qx[i], qy[i], up(qx[i], qy[i]), qy[i], ox[i], oy[i]);
                add1(qx[i], qy[i], down(qx[i], qy[i]), qy[i], ox[i], oy[i]);
                }
            qp2 = 0;
            for (i = 0; i < qp && f == -1; i ++) {
                if (qx[i] + 1 < n && data[qx[i] + 1][qy[i]] == '.')
                    add2(qx[i] + 1, qy[i], ix[i], iy[i], ox[i], oy[i]);
                if (qx[i] - 1 >= 0 && data[qx[i] - 1][qy[i]] == '.')
                    add2(qx[i] - 1, qy[i], ix[i], iy[i], ox[i], oy[i]);
                if (qy[i] + 1 < m && data[qx[i]][qy[i] + 1] == '.')
                    add2(qx[i], qy[i] + 1, ix[i], iy[i], ox[i], oy[i]);
                if (qy[i] - 1 >= 0 && data[qx[i]][qy[i] - 1] == '.')
                    add2(qx[i], qy[i] - 1, ix[i], iy[i], ox[i], oy[i]);
                
                if (qx[i] == ix[i] && qy[i] == iy[i])
                    add2(ox[i], oy[i], ix[i], iy[i], ox[i], oy[i]);
                }
            qp = qp2;
            for (i = 0; i < qp; i ++) {
                qx[i] = qx2[i];
                qy[i] = qy2[i];
                ix[i] = ix2[i];
                iy[i] = iy2[i];
                ox[i] = ox2[i];
                oy[i] = oy2[i];
                }
            c ++;
            }
        
        if (f == -1)
            printf("Case #%d: THE CAKE IS A LIE\n", ++ct);
        else
            printf("Case #%d: %d\n", ++ct, f);
        }
    
    return 0;
    }
