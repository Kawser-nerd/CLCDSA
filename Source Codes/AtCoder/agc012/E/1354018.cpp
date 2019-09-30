#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cassert>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) { // [l, r), p is monotone
    assert (l < r);
    -- l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x | p(x) }
}

int main() {
    // input
    int n, v; scanf("%d%d", &n, &v);
    vector<int> x(n); repeat (i, n) scanf("%d", &x[i]);
    // solve
    vector<int> vs;
    for (int cur_v = v; cur_v > 0; cur_v /= 2) vs.push_back(cur_v);
    vs.push_back(0);
    whole(reverse, vs);
    int k = vs.size();
    vector<vector<pair<int, int> > > range(k); // [l, r]
    repeat (l, n) {
        range[0].emplace_back(l, l);
    }
    repeat (i, k-1) {
        int v = vs[i+1]; // shadowing
        for (int j = 0; j < range[i].size(); ) {
            int l1, r1; tie(l1, r1) = range[i][j];
            ++ j;
            while (j < range[i].size()) {
                int l2, r2; tie(l2, r2) = range[i][j];
                assert (r1 + 1 == l2);
                if (x[l2] - x[r1] <= v) {
                    r1 = r2;
                    ++ j;
                } else {
                    break;
                }
            }
            range[i+1].emplace_back(l1, r1);
        }
    }
    vector<int> dp_l(1 << (k-1));
    vector<int> dp_r(1 << (k-1), n-1);
    repeat (s, 1 << (k-1)) {
        repeat (i, k-1) if (not (s & (1 << i))) {
            int t = s | (1 << i);
            int jr = binsearch(0, range[i].size(), [&](ll j) {
                int l, r; tie(l, r) = range[i][j];
                return dp_l[s] < l;
            }) - 1;
            int jl = binsearch(0, range[i].size(), [&](ll j) {
                int l, r; tie(l, r) = range[i][j];
                return dp_r[s] <= r;
            });
            setmax(dp_l[t], jr < range[i].size() ? range[i][jr].second + 1 :  n);
            setmin(dp_r[t], jl < range[i].size() ? range[i][jl].first  - 1 : -1);
        }
    }
    // output
    for (auto it : range[k-1]) {
        int l, r; tie(l, r) = it;
        bool possible = false;
        repeat (s, 1 << (k-1)) {
            int t = ((1 << (k-1)) - 1) & ~ s;
            if (l <= dp_l[s] and dp_r[t] <= r) {
                possible = true;
                break;
            }
        }
        repeat (i, r - l + 1) {
            printf("%s\n", possible ? "Possible" : "Impossible");
        }
    }
    return 0;
}