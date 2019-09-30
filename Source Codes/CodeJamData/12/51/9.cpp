#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int p[MAXN], q[MAXN], r[MAXN];

int main() {
    int re, n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &q[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
        }
        for (int i = 0; i < n; ++i) {
            r[i] = i;
        }
        stable_sort(r, r + n, [&](int i, int j) {
            return q[i] * p[j] < q[j] * p[i];
        });
        printf("Case #%d:", ri);
        for (int i = 0; i < n; ++i) {
            printf(" %d", r[i]);
        }
        puts("");
    }

    return 0;
}

