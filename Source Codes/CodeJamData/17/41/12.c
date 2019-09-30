#include <stdio.h>

int S[4] = {};

void solve() {
    int n, p;
    scanf("%i%i", &n, &p);

    int i;
    for (i = 0; i < p; ++i) S[i] = 0;

    int x;
    for (i = 0; i < n; ++i) {
        scanf("%i", &x);
        S[x % p]++;
    }

    int res = 0;

    if (p == 2) {
        res = S[0] + (S[1] + 1) / 2;
    }
    else if (p == 3) {
        res = S[0];

        int min = S[1];
        if (S[2] < min) min = S[2];

        res += min;
        S[1] -= min;
        S[2] -= min;

        res += (S[1] + 2) / 3;
        res += (S[2] + 2) / 3;
    }

    printf("%i\n", res);
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        printf("Case #%i: ", ti);
        solve();
    }
}
