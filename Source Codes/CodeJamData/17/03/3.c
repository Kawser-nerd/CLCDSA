#include <inttypes.h>
#include <stdio.h>
#include <string.h>

struct node {
    int64_t size;
    int64_t n;
};

struct node a[70][10];

int ti, tn, cnt[70], cur, i, j;
int64_t k, x;

int
main()
{
    fscanf(stdin, "%d", &tn);
    for (ti = 1; ti <= tn; ++ti) {
        fprintf(stdout, "Case #%d: ", ti);
        fscanf(stdin, "%" PRId64 " %" PRId64, &(a[0][1].size), &k);
        cnt[0] = 1;
        a[0][1].n = 1;
        for (cur = 1; k; ++cur) {
            cnt[cur] = 0;
            for (i = 1; k && i <= cnt[cur - 1]; ++i)
                if (k > a[cur - 1][i].n) {
                    k -= a[cur - 1][i].n;
                    x = (a[cur - 1][i].size - 1) >> 1;
                    for (j = 1; j <= cnt[cur] && a[cur][j].size != x; ++j);
                    if (j > cnt[cur]) {
                        ++cnt[cur];
                        a[cur][j].size = x;
                        a[cur][j].n = a[cur - 1][i].n;
                    } else
                        a[cur][j].n += a[cur - 1][i].n;
                    x = a[cur - 1][i].size - 1 - x;
                    for (j = 1; j <= cnt[cur] && a[cur][j].size != x; ++j);
                    if (j > cnt[cur]) {
                        ++cnt[cur];
                        a[cur][j].size = x;
                        a[cur][j].n = a[cur - 1][i].n;
                    } else
                        a[cur][j].n += a[cur - 1][i].n;
                } else {
                    k = 0;
                    fprintf(stdout, "%" PRId64 " %" PRId64 "\n", a[cur - 1][i].size - 1 - ((a[cur - 1][i].size - 1) >> 1), (a[cur - 1][i].size - 1) >> 1);
                }
            for (i = 1; i < cnt[cur]; ++i)
                for (j = i + 1; j <= cnt[cur]; ++j)
                    if (a[cur][i].size < a[cur][j].size) {
                        a[cur][i].size ^= a[cur][j].size;
                        a[cur][j].size ^= a[cur][i].size;
                        a[cur][i].size ^= a[cur][j].size;
                        a[cur][i].n ^= a[cur][j].n;
                        a[cur][j].n ^= a[cur][i].n;
                        a[cur][i].n ^= a[cur][j].n;
                    }
        }
    }

    return 0;
}
