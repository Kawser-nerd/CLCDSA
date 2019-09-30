#include <stdio.h>
#include <string.h>

struct node {
    int pos;
    int cus;
} a[1000], tmp;

int ti, tn, cnt[1001], stat[1001][1001], n, c, m, f, t, mid;

int can(int);

int
main()
{
    int i, j;

    fscanf(stdin, "%d", &tn);
    for (ti = 1; ti <= tn; ++ti) {
        fprintf(stdout, "Case #%d: ", ti);
        fscanf(stdin, "%d%d%d", &n, &c, &m);
        memset(cnt, 0, sizeof(cnt));
        for (i = 0; i < m; ++i)
            fscanf(stdin, "%d%d", &a[i].pos, &a[i].cus);
        for (i = 0; i < m; ++i)
            for (j = i + 1; j < m; ++j)
                if (a[i].pos > a[j].pos) {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
        for (f = 1; f <= m; ++f)
            if (can(f))
                break;
        for (i = t = 0; i < m; ) {
            for (j = i + 1; j < m && a[j].pos == a[i].pos; ++j);
            if (j - i > f)
                t += j - i - f;
            i = j;
        }
        fprintf(stdout, "%d %d\n", f, t);
    }
    return 0;
}

int
can(int h)
{
    int i, j, k;

    memset(stat, 0, sizeof(stat));
    for (i = 0; i < m; ++i) {
        for (j = 1; j <= h; ++j) {
            for (k = 1; k <= a[i].pos; ++k)
                if (stat[j][k] == a[i].cus)
                    break;
            if (k <= a[i].pos)
                continue;
            for (k = 1; k <= a[i].pos; ++k)
                if (stat[j][k] == 0)
                    break;
            if (k <= a[i].pos) {
                stat[j][k] = a[i].cus;
                break;
            }
        }
        if (j > h)
            return 0;
    }
    return 1;
}
