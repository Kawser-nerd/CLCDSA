#include <array>
#include <cstdio>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
using ll = long long;
using namespace std;

constexpr int mod = 1e9+7;
int main() {
    // input
    int n; ll a, b; scanf("%d%lld%lld", &n, &a, &b);
    vector<ll> s(n); repeat (i, n) scanf("%lld", &s[i]);
    if (a > b) swap(a, b);
    // solve
    s.insert(s.begin(), s.front() - a - b);
    s.insert(s.end(),   s.back()  + a + b);
    s.insert(s.end(),   s.back()  + a + b);
    vector<array<int, 2> > dp(n + 2);
    vector<int> acc(dp.size() + 1);
    dp[0][0] = 1;
    acc[1] = 1;
    int l_l = 0, l_r = 0;
    repeat_from (r, 1, dp.size()) {
        while (l_r < r - 1 and s[l_r] + b <= s[r]) ++ l_r;
        if (l_l <= l_r) {
            dp[r][0] = (acc[l_r] - acc[l_l] +(ll) mod) % mod;
        }
        if (not (s[r - 1] + a <= s[r])) l_l = r - 1;
        dp[r][1] = (s[r - 1] + b <= s[r]) ? (dp[r - 1][0] + dp[r - 1][1]) % mod : 0;
        acc[r + 1] = (0ll + acc[r]
                + (s[r - 1] + a <= s[r + 1] ? dp[r][0] : 0)
                + dp[r][1] ) % mod;
    }
    // output
    int result = (dp[n + 1][0] + dp[n + 1][1]) % mod;
    printf("%d\n", result);
    return 0;
}