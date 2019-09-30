#include <stdio.h>

int ti, tn, i, n, p, x, a[4], ans;

int
main()
{
    fscanf(stdin, "%d", &tn);
    for (ti = 1; ti <= tn; ++ti) {
        fprintf(stdout, "Case #%d: ", ti);
        fscanf(stdin, "%d%d", &n, &p);
        for (i = ans = a[1] = a[2] = a[3] = 0; i < n; ++i) {
            fscanf(stdin, "%d", &x);
            if (x % p == 0)
                ++ans;
            else
                ++a[x % p];
        }
        if (p == 2)
            ans += (a[1] + 1) / 2;
        else if (p == 3) {
            if (a[1] > a[2]) {
                a[1] ^= a[2];
                a[2] ^= a[1];
                a[1] ^= a[2];
            }
            ans += a[1];
            a[2] -= a[1];
            ans += (a[2] + 2) / 3;
        } else {
            x = a[1] < a[3] ? a[1] : a[3];
            ans += x;
            a[1] -= x;
            a[3] -= x;
            ans += (a[1] + a[3] + 3) / 4;
            ans += (a[2] + 1) / 2;
        }
        fprintf(stdout, "%d\n", ans);
    }

    return 0;
}
