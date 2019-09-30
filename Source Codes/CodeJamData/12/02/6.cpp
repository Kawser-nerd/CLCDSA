/*
Author: Shu LIN
Data: 2012/4/14
language: C++
*/

#include<iostream>
#include<stdio.h>
#include<algorithm>

int t[100];

int main() {
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);

    int cases, s, p, n, a, b;
    int i, j, k, x;

    scanf("%d", &cases);
    for (x = 1; x <= cases; ++x) {
        printf("Case #%d: ", x);

        scanf("%d%d%d", &n, &s, &p);
        for (i = 0; i < n; ++i)
            scanf("%d", &t[i]);

        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j)
                if (t[i] < t[j]) {
                    k = t[i];
                    t[i] = t[j];
                    t[j] = k;
                }

        for (i = 0; i < n; ++i) {
            switch (t[i] % 3) {
            case 0:
                a = t[i] / 3;
                if (t[i] == 0)
                    b = 0;
                else
                    b = t[i] / 3 + 1;
                break;
            case 1:
                a = b = t[i] / 3 + 1;
                break;
            case 2:
                a = t[i] / 3 + 1;
                b = t[i] / 3 + 2;
            }
            if (a < p)
                if (b >= p) {
                    --s;
                    if (s < 0)
                        break;
                }
                else
                    break;
        }

        printf("%d\n", i);
    }

    return 0;
}