#include <stdio.h>

typedef unsigned long long lint;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        lint n, k;
        scanf("%llu%llu", &n, &k);

        lint total = 1;
        int level = 1;

        lint one = n;
        lint two = n;

        lint cone = 1;
        lint ctwo = 0;

        while (k > total) {
            ++level;
            total = 2 * total + 1;

            lint n1, n2;
            lint c1, c2;

            if (one % 2 == 0) {
                n1 = (one / 2) - 1;
                n2 = one / 2;

                c1 = cone;
                c2 = cone + 2 * ctwo;
            }
            else if (two % 2 == 0) {
                n1 = (two / 2) - 1;
                n2 = two / 2;

                c1 = 2 * cone + ctwo;
                c2 = ctwo;
            }
            else {
                n1 = one / 2;
                n2 = one / 2;

                c1 = 2 * cone + 2 * ctwo;
                c2 = 0;
            }

            one = n1;
            two = n2;

            cone = c1;
            ctwo = c2;
        }

        lint totprev = total / 2;
        if (k <= totprev + ctwo) {
            n = two;
        }
        else {
            n = one;
        }

        if (n % 2 == 0) {
            one = (n / 2) - 1;
            two = n / 2;
        }
        else {
            one = n / 2;
            two = n / 2;
        }

        lint max = (one > two) ? one : two;
        lint min = (one < two) ? one : two;

        printf("Case #%i: %llu %llu\n", ti, max, min);
    }

    return 0;
}

