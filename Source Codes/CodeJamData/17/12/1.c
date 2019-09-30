#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

int R[50];
int Q[50][50];
int P[50];

int intcmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        printf("Case #%i: ", ti);

        int n, p;
        scanf("%i%i", &n, &p);

        int i, j;
        for (i = 0; i < n; ++i) scanf("%i", &R[i]);

        for (i = 0; i < n; ++i) {
            for (j = 0; j < p; ++j) {
                scanf("%i", &Q[i][j]);
            }
        }

        for (i = 0; i < n; ++i) {
            qsort(Q[i], p, sizeof(int), intcmp);
        }

        int count = 0;

        for (i = 0; i < n; ++i) P[i] = 0;

        int min = 1;
        while (1) {
            for (i = 0; i < n; ++i) {
                u64 val = (u64)R[i] * min;
                u64 low = val * 9 / 10;
                u64 high = val * 10 / 9;

                while (P[i] < p && (u64)Q[i][P[i]] < low) ++P[i];

                if (P[i] >= p) goto done;

                if (Q[i][P[i]] > high) {
                    min = ((u64)Q[i][P[i]] * 9 / 10) / R[i];

                    val = (u64)R[i] * min;
                    low = val * 9 / 10;
                    high = val * 10 / 9;

                    if (Q[i][P[i]] < low || Q[i][P[i]] > high) {
                        ++min;

                        val = (u64)R[i] * min;
                        low = val * 9 / 10;
                        high = val * 10 / 9;

                        if (Q[i][P[i]] < low || Q[i][P[i]] > high) ++P[i];
                    }

                    break;
                }
            }

            if (i == n) {
                for (i = 0; i < n; ++i) ++P[i];
                ++count;
            }
        }

        done: ;
        printf("%i\n", count);
    }

    return 0;
}
