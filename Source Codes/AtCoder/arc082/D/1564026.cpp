#include <algorithm>
#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
using ll = long long;
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

constexpr int inf = 1e9+7;
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
        setmax(hi[i + 1], 0); setmin(hi[i + 1], x);
        setmax(ub[i + 1], 0); setmin(ub[i + 1], x);
        setmax(lb[i + 1], 0); setmin(lb[i + 1], x);
        setmax(lo[i + 1], 0); setmin(lo[i + 1], x);
    }
    int q; scanf("%d", &q);
    while (q --) {
        int t, a; scanf("%d%d", &t, &a);
        auto j = (upper_bound(whole(r), t) - r.begin()) - 1;
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