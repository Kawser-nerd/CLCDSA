#include<stdio.h>
#define SZ 100001

inline void readint(int *n) {
    int c;
    *n = 0;
    while ((c = getchar_unlocked()) >= '0') *n = ((*n << 2) + *n << 1) + c - '0';
}
inline void writeint(int n) {
    // n > 0
    char buf[9];
    int i = 0;
    for (; n > 0; n /= 10) buf[i++] = n % 10 + '0';
    for (--i; i >= 0; --i) putchar_unlocked(buf[i]);
    putchar_unlocked('\n');
}
int main() {
    int n, m, d;
    readint(&n); readint(&m); readint(&d);
    int a[200001];
    for (int i = 0; i < m; ++i) readint(a + i);
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
        int j = 0;
        for (int p = i; !~ii[p]; ++j, p = nex[p]) {
            ii[p] = i;
            ij[p] = j;
            l[i][j] = p;
        }
        sz[i] = j;
        ind += j;
        writeint(l[ii[i]][(d + ij[i]) % sz[ii[i]]] + 1);
    }
    return 0;
}