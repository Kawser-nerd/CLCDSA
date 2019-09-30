#include <cstdio>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < int(n); ++(i))
using ll = long long;
using namespace std;
constexpr int mod = 1e9+7;
int main() {
    int n; scanf("%d", &n);
    // count free sequences
    vector<ll> dp(2*n);
    vector<ll> acc(2*n+1);
    dp[0] = 1;
    acc[1] = 1;
    repeat_from (i,1,2*n) {
        int l = max(0, i-n-1);
        int r = max(0, min(n-1, i-2));
        dp[i] = (acc[r] - acc[l] + (i-1 < n-1 ? dp[i-1] : 0)) % mod;
        acc[i+1] = (acc[i] + dp[i]) % mod;
    }
    // compute the result
    ll result = 0;
    repeat (i,n-1) {
        result += dp[i] * (n-1) % mod * (n-1) % mod;
    }
    result += dp[n-1] * n % mod;
    repeat_from (i,n,2*n) {
        result += dp[i] % mod;
    }
    result %= mod;
    if (result < 0) result += mod;
    printf("%lld\n", result);
    return 0;
}