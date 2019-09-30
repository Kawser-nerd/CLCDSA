#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100000;
const int SQ = 316;
int cnt[MAX];
int ans[MAX];

struct Q {
    int l, r;
    bool operator<(const Q& q) const {
        if (l/SQ != q.l/SQ) return l < q.l;
        return q.r < r;
    }
};

Q qs[MAX * 3];

vector<int> factor[MAX];

void add(int x, int c) {
    for (int f : factor[x]) if (cnt[f]++ == 0) ans[f] += c;
}
void del(int x, int c) {
    for (int f : factor[x]) if (--cnt[f] == 0) ans[f] -= c;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &qs[i].l, &qs[i].r);
        qs[i].r++;
    }
    sort(qs, qs + n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j*j <= i; j++) {
            if (i % j == 0) {
                factor[i].push_back(j-1);
                if (j*j != i) factor[i].push_back(i/j-1);
            }
        }
    }
    for (int l = 0, r = 0, i = 0; i < n; i++) {
        while (l > qs[i].l) { l--; add(l, n-i); }
        while (r < qs[i].r) { add(r, n-i); r++; }
        while (l < qs[i].l) { del(l, n-i); l++; }
        while (r > qs[i].r) { r--; del(r, n-i); }
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}