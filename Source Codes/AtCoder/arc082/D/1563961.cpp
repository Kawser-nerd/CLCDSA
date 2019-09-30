#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i, m, n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(x) begin(x), end(x)
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) { // [l, r), p is monotone
    assert (l < r);
    -- l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x in [l, r) | p(x) }, or r
}

const int inf = 1e9+7;
int main() {
    int x, k; scanf("%d%d", &x, &k);
    vector<int> r(k); repeat (i, k) scanf("%d", &r[i]);
    if (r[0]) r.insert(r.begin(), 0);
    r.push_back(inf);
    vector<int> hi(k + 1, x);
    vector<int> ub(k + 1, x);
    vector<int> lb(k + 1);
    vector<int> lo(k + 1);
    repeat (i, k) {
        ll dt = r[i + 1] - r[i];
        if (i % 2 == 0) {
            hi[i + 1] = hi[i] - dt;
            ub[i + 1] = ub[i];
            lo[i + 1] = lo[i] - dt;
            lb[i + 1] = lb[i] + max<ll>(0, - lo[i + 1]);
        } else {
            hi[i + 1] = hi[i] + dt;
            lb[i + 1] = lb[i];
            lo[i + 1] = lo[i] + dt;
            ub[i + 1] = ub[i] - max(0, hi[i + 1] - x);
        }
        setmin(hi[i + 1], x); setmax(hi[i + 1], 0);
        setmin(ub[i + 1], x); setmax(ub[i + 1], 0);
        setmin(lb[i + 1], x); setmax(lb[i + 1], 0);
        setmin(lo[i + 1], x); setmax(lo[i + 1], 0);
        if (hi[i + 1] == 0) ub[i + 1] = 0;
        if (lo[i + 1] == x) lb[i + 1] = x;
    }
    int q; scanf("%d", &q);
    while (q --) {
        int t, a; scanf("%d%d", &t, &a);
        int j = binsearch(0, r.size(), [&](int i) {
            return r[i] > t;
        }) - 1;
        if (a <= lb[j]) {
            a = lo[j];
        } else if (ub[j] <= a) {
            a = hi[j];
        } else {
            a = (a - lb[j]) + lo[j];
        }
        int dt = t - r[j];
        a = j & 1 ? min(x, a + dt) : max(0, a - dt);
        printf("%d\n", a);
    }
    return 0;
}