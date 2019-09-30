#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
typedef struct _t {
    double x, y, r;
} CIR;
CIR cir[1000];
int n;
double get_dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int tc, cn;
    int i, j, k;
    double a, b, c;
    double dist;
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d", &n);
        for (i = 0; i < n ;i++) {
            scanf("%lf%lf%lf", &cir[i].x, &cir[i].y, &cir[i].r);
        }
        if (n == 1) {
            printf("Case #%d: %.6lf\n", cn, cir[0].r);
            continue;
        }
        else if (n == 2) {
            printf("Case #%d: %.6lf\n", cn, max(cir[0].r, cir[1].r));
            continue;
        }
        // 0 - 1
        dist = get_dist(cir[0].x, cir[0].y, cir[1].x, cir[1].y);
        dist += cir[0].r + cir[1].r;
        a = max(dist * 0.5, cir[2].r);
        // 0 - 2
        dist = get_dist(cir[0].x, cir[0].y, cir[2].x, cir[2].y);
        dist += cir[0].r + cir[2].r;
        b = max(dist * 0.5, cir[1].r);
        // 1 - 2
        dist = get_dist(cir[1].x, cir[1].y, cir[2].x, cir[2].y);
        dist += cir[1].r + cir[2].r;
        c = max(dist * 0.5, cir[0].r);
        dist= min(a, min(b, c));
        printf("Case #%d: %.6lf\n", cn, dist);
    }
    return 0;
}
