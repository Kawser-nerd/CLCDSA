#include <stdio.h>

int A[1001][10001];
Sum[1001];

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

void solve() {
    int n, c, m;
    scanf("%i%i%i", &n, &c, &m);

    int i, j;
    for (i = 0; i <= c; ++i) {
        for (j = 0; j <= n; ++j) A[i][j] = 0;

        Sum[i] = 0;
    }

    for (i = 0; i < m; ++i) {
        int p, s;
        scanf("%i%i", &s, &p);
        A[p][s]++;
        Sum[p]++;
    }

    int val1;
    int val2;
    int val;

    for (i = 1; i <= n; ++i) {
        val1 = A[1][i] - (Sum[2] - A[2][i]);
        val2 = A[2][i] - (Sum[1] - A[1][i]);

        val = min(val1, val2);

        if (val > 0) break;
    }

    int res = 0;
    int resp = 0;

    res = max(Sum[1], Sum[2]);

    if (i <= n) {
        if (i == 1) res += val;
        else resp += val;
    }

    printf("%i %i\n", res, resp);
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        printf("Case #%i: ", ti);
        solve();
    }
}
