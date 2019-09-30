#include<stdio.h>
#define SZ 100010

inline int readint() {
    int c, n;
    n = getchar_unlocked() - '0';
    while ((c = getchar_unlocked()) >= '0') n = 10 * n + c - '0';
    return n;
}
int main() {
    int n = readint();
    int m = readint();
    int d = readint();
    if (m == 0) {
        for (int i = 1; i <= n; ++i) printf("%d\n", i);
        return 0;
    }
    int a[SZ * 2];
    for (int i = 0; i < m; ++i) a[i] = readint();

    int nex[SZ], ii[SZ], ij[SZ], sz[SZ], buf[SZ];
    for (int i = 0; i < n; ++i) {
        nex[i] = i;
        ii[i] = ij[i] = -1;
    }
    for (int i = m - 1; i >= 0; --i) {
        int t = nex[a[i] - 1]; nex[a[i] - 1] = nex[a[i]]; nex[a[i]] = t;
    }
    int *l[SZ];
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        l[i] = buf + ind;
        int p = i, j = 0;
        for (; ii[p] == -1; ++j, ++ind, p = nex[p]) {
            ii[p] = i;
            ij[p] = j;
            l[i][j] = p;
        }
        sz[i] = j;
        printf("%d\n", l[ii[i]][(d + ij[i]) % sz[ii[i]]] + 1);
    }
    return 0;
}