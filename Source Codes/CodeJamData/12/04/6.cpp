/*
Author: Shu LIN
Data: 2012/4/14
language: C++
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

const double EPS = 1e-6;

char g[40][40];
bool exist[100 + 5][100 + 5];

int gcd(int a, int b)
{
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	if (b < 0)
		return - b;
	return b;
}

int main() {
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);

    int cases, cur;
    int h, w, d;
    int i, j, k, s, px, py, ii, jj, ox, oy;
    double x, y, cx, cy, l, a, b;
    bool flag;

    scanf("%d", &cases);

    for (cur = 1; cur <= cases; ++cur) {
        printf("Case #%d: ", cur);

        scanf("%d%d%d", &h, &w, &d);
        for (i = 0; i < h; ++i)
            for (j = 0; j < w; ++j) {
                scanf(" %c", &g[i][j]);
                if (g[i][j] == 'X') {
                    x = i + 0.5;
                    y = j + 0.5;
                }
            }

        s = 0;

        for (px = (int)x - 1, k = 1; g[px][(int)y] == '.'; --px, k += 2);
        if (k <= d)
            ++s;
        for (px = (int)x + 1, k = 1; g[px][(int)y] == '.'; ++px, k += 2);
        if (k <= d)
            ++s;
        for (py = (int)y - 1, k = 1; g[(int)x][py] == '.'; --py, k += 2);
        if (k <= d)
            ++s;
        for (py = (int)y + 1, k = 1; g[(int)x][py] == '.'; ++py, k += 2);
        if (k <= d)
            ++s;

		for (i = -d + 1; i < d; ++i)
			for (j = -d + 1; j < d; ++j)
				exist[i + 50][j + 50] = false;
        for (ii = -d + 1; ii < d; ++ii)
            if (ii != 0)
                for (jj = -d + 1; jj < d; ++jj)
                    if (jj != 0 && ii * ii + jj * jj <= d * d) {
                        i = ii;
                        j = jj;
                        cx = x;
                        cy = y;
                        l = 0;
                        flag = true;
                        while (flag) {
                            if (i < 0)
                                a = (cx - (int)(cx - EPS)) / -i;
                            else
                                a = ((int)(cx + 1 + EPS) - cx) / i;
                            if (j < 0)
                                b = (cy - (int)(cy - EPS)) / -j;
                            else
                                b = ((int)(cy + 1 + EPS) - cy) / j;
                            if (a > b)
                                a = b;
                            if (l + a > 1)
                                break;
                            l += a;
                            cx += a * i;
                            cy += a * j;
                            px = (int)(cx + EPS);
                            py = (int)(cy + EPS);
                            if (cx - px < EPS && cy - py < EPS) {
                                if (i < 0) {
                                    ox = px;
                                    --px;
                                }
                                else
                                    ox = px - 1;
                                if (j < 0) {
                                    oy = py;
                                    --py;
                                }
                                else
                                    oy = py - 1;
                                if (g[px][py] == '#') {
                                    flag = false;
                                    if (g[ox][py] == '#') {
                                        flag = true;
                                        j = -j;
                                    }
                                    if (g[px][oy] == '#') {
                                        flag = true;
                                        i = -i;
                                    }
                                }
                            }
                            else
                                if (cx - px < EPS) {
                                    if (i < 0)
                                        --px;
                                    if (g[px][py] == '#')
                                        i = -i;
                                }
                                else
                                    if (cy - py < EPS) {
                                        if (j < 0)
                                            --py;
                                        if (g[px][py] == '#')
                                            j = -j;
                                    }
                        }
                        if (flag) {
                            a = (x - cx) / i;
                            b = (y - cy) / j;
                            if (fabs(l + a - 1) < EPS && fabs(l + b - 1) < EPS) {
								k = gcd(ii, jj);
								i = ii / k;
								j = jj / k;
								if (!exist[i + 50][j + 50]) {
									++s;
									exist[i + 50][j + 50] = true;
								}
							}
                        }
                    }

        printf("%d\n", s);
    }
    return 0;
}