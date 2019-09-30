#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

struct Range {
    int len, left, right;
};

bool sort_by_len(const Range &a, const Range &b) {
    return a.len < b.len;
}

struct LazySegmentTree {
private:
    int n;
    vector <ll> node, lazy;
public:
    LazySegmentTree(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
    }
    void eval(int k, int l, int r) {
        if (lazy[k] > 0) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    void add(int a, int b, int val, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += val * (r - l);
            eval(k, l, r);
        } else {
            add(a, b, val, 2*k+1, l, (l+r)/2);
            add(a, b, val, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
    ll get(int a, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (r <= a || a < l) return 0;
        if (a == l && r == a + 1) return node[k];
        ll vl = get(a, 2*k+1, l, (l+r)/2);
        ll vr = get(a, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <Range> vec(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        vec[i] = (Range) {r-l+1, l, r};
    }

    sort(vec.begin(), vec.end(), sort_by_len);

    int idx = 0;
    LazySegmentTree seg(m + 1);
    for (int d = 1; d <= m; d++) {
        while (idx < n && vec[idx].len < d) {
            seg.add(vec[idx].left, vec[idx].right + 1, 1);
            idx++;
        }

        int ans = n - idx;
        for (int i = d; i <= m; i += d) ans += seg.get(i);
        cout << ans << "\n";
    }

    return 0;
}