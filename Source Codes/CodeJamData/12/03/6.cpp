/*
Author: Shu LIN
Data: 2012/4/14
language: C++
*/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int m[2000000 + 5];
int t[2000000 + 5];

int main() {
    // freopen("c.in", "r", stdin);
    // freopen("c.out", "w", stdout);

    int cases, x;
    int a, b;
    int i, j, k, l, s;

    scanf("%d", &cases);

    k = 1;
    j = 0;

    for (i = 1; i <= 2000000; ++i) {
        if (k * 10 <= i) {
            k *= 10;
            ++j;
        }
        m[i] = i;
        s = i;
        for (l = 0; l < j; ++l) {
            s = s % k * 10 + s / k;
            if (s >= k && s < m[i])
                m[i] = s;
		}
    }

    for (x = 1; x <= cases; ++x) {
        printf("Case #%d: ", x);

        scanf("%d%d", &a, &b);
        for (i = a; i <= b; ++i)
            t[i] = m[i];
        sort(t + a, t + b + 1);

        k = 1;
        s = 0;
        for (i = a + 1; i <= b; ++i)
            if (t[i] == t[i - 1]) {
                s += k;
                ++k;
            }
            else
                k = 1;
        printf("%d\n", s);
    }

    return 0;
}