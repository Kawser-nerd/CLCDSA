#include <stdio.h>
#include <string.h>
typedef struct _pt {
    int x, y;
} POINT;
int get_area(POINT* pt, int n)
{
    int i;
    int a, b, sum;
    sum = 0;
    /* pt[n] = pt[0] */
    for (i = 1; i <= n; i++) {
        a = (pt[i-1].x * pt[i].y);
        b = (pt[i].x * pt[i-1].y);
        sum += (a - b);
    }
    return sum;
}
int main()
{
    int tc, cn;
    int i, j, k, l;
    int a, x;
    int n, m;
    POINT p[5];
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d%d%d", &n, &m, &x);
        p[0].x = 0;
        p[0].y = 0;        
        p[3].x = p[0].x;
        p[3].y = p[0].y;
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= m; j++) {
                p[1].x = i;
                p[1].y = j;
                for (k = 0; k <= n; k++) {
                    for (l = 0; l <= m; l++) {
                        p[2].x = k;
                        p[2].y = l;
                        a = get_area(p, 3);
                        if (a == x) {
                            printf("Case #%d: %d %d %d %d %d %d\n", cn, p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
                            goto X;
                        }
                    }
                }
            }
        }
        printf("Case #%d: IMPOSSIBLE\n", cn);
        continue;
X: ;
    }
    return 0;
}
