#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
using ll = long long;
using namespace std;
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

constexpr ll inf = ll(1e18)+9;
int main() {
    // input
    int n, e, t; scanf("%d%d%d", &n, &e, &t);
    vector<int> x(n); repeat (i, n) scanf("%d", &x[i]);
    // solve
    vector<ll> dp(n + 1, inf);
    dp[n] = e;
    int m = n;
    ll acc = inf;
    repeat_reverse (l, n) {
        for (; m - 1 >= l + 1 and t <= 2ll * (x[m - 1] - x[l]); -- m) {
            setmin(acc, 2ll * x[m - 1] + dp[m]);
        }
        dp[l] = min(acc - 2ll * x[l], t + dp[m]);
    }
    // output
    printf("%lld\n", dp[0]);
    return 0;
}