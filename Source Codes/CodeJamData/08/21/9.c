#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct _p {
    int x, y;
} POINT;
POINT pt[1000];
int main()
{
    int tc, cn;
    int n, cnt;
    int i, j, k;
    int A, B, C, D, x0, y0, M;
    long long X, Y;
    double cx, cy, tempx, tempy;
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d%d%d%d%d%d%d%d", &n, &A, &B, &C, &D, &x0, &y0, &M);
        X = x0;
        Y = y0;
        pt[0].x = X;
        pt[0].y = Y;
        for (i = 1; i < n; i++) {
            X = (A * X + B) % M;
            Y = (C * Y + D) % M;
            pt[i].x = X;
            pt[i].y = Y;
        }

        cnt = 0;
        for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
        for (k = j+1; k < n; k++) {
            cx = (double)(pt[i].x + pt[j].x + pt[k].x) / 3.0;
            cy = (double)(pt[i].y + pt[j].y + pt[k].y) / 3.0;
            tempx = floor(cx + 1e-8);
            tempy = floor(cy + 1e-8);
            if (fabs(cx-tempx) < 1e-8 && fabs(cy - tempy) < 1e-8) {
                cnt++;
            }
        }
        }
        }
        printf("Case #%d: %d\n", cn, cnt);
    }
    return 0;
}
