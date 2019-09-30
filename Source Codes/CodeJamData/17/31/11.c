#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _pancake {
    int r;
    int h;
    double w;
    double s;
} pancake;

double w(int r, int h)
{
    return 2. * M_PI * r * h;
}

double s(int r)
{
    return M_PI * r * r;
}

int cmpfunc(const void *v1, const void *v2)
{
    const pancake *p1 = (pancake *)v1;
    const pancake *p2 = (pancake *)v2;
    if (p1->w - p2->w > 1e-6)
        return -1;
    else if (p2->w - p1->w > 1e-6)
        return 1;
    else if (p1->s - p2->s > 1e-6)
        return -1;
    else if (p2->s - p1->s > 1e-6)
        return 1;
    else
        return 0;
}

int main()
{
    int t, n, k;
    pancake p[1001];
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &k);
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &p[j].r, &p[j].h);
            p[j].w = w(p[j].r, p[j].h);
            p[j].s = s(p[j].r);
        }
        qsort(p, n, sizeof(pancake), cmpfunc);
        //for (int j = 0; j < n; j++)
        //    printf(">> %d %d %d %f %f\n", j, p[j].r, p[j].h, p[j].w, p[j].s);

        double result = 0;
        for (int j = 0; j < k - 1; j++) {
            result += p[j].w;
        }
        double ss = 0;
        for (int j = 0; j < k - 1; j++) {
            if (p[j].s > ss) ss = p[j].s;
        }
        ss += p[k - 1].w;
        for (int j = k - 1; j < n; j++) {
            if (p[j].w + p[j].s > ss) ss = p[j].w + p[j].s;
        }
        result += ss;

        printf("Case #%d: %f\n", i + 1, result);
    }

    return 0;
}
