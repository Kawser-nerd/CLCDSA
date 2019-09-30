#include <stdio.h>
#include <inttypes.h>

#define PI 3.1415926535897932384626433832795
#define TPI 6.283185307179586476925286766559

struct node {
    int64_t r;
    int64_t h;
    int64_t rr;
    int64_t rh;
} a[1002], tmp;
int64_t s[1002], itmp;
int ti, tn, i, j, l, n, k;
double ans, cur;

int
main()
{
    fscanf(stdin, "%d", &tn);
    for (ti = 1; ti <= tn; ++ti) {
        fprintf(stdout, "Case #%d: ", ti);
        fscanf(stdin, "%d%d", &n, &k);
        for (i = 0; i < n; ++i) {
            fscanf(stdin, "%" PRId64 "%" PRId64, &a[i].r, &a[i].h);
            a[i].rr = a[i].r * a[i].r;
            a[i].rh = a[i].r * a[i].h;
        }
        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j)
                if (a[i].rr < a[j].rr) {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
        for (ans = 0.0, i = 0; i + k <= n; ++i) {
            cur = PI * a[i].rr + TPI * a[i].rh;
            for (j = i + 1; j < n; ++j)
                s[j - i - 1] = a[j].rh;
            for (j = 0; j < n - i - 1; ++j)
                for (l = j + 1; l < n - i - 1; ++l)
                    if (s[j] < s[l]) {
                        itmp = s[j];
                        s[j] = s[l];
                        s[l] = itmp;
                    }
            for (j = 0; j < k - 1; ++j)
                cur += TPI * s[j];
            if (cur > ans)
                ans = cur;
        }
        fprintf(stdout, "%.6lf\n", ans);
    }

    return 0;
}
