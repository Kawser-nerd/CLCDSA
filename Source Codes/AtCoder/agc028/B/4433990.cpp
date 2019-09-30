#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll MOD = 1000000007LL;

ll pow_mod(ll num, ll pow) {
    ll prod = 1;
    num %= MOD;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % MOD;
        num = num * num % MOD;
        pow >>= 1;
    }
    return prod;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, a;
    cin >> n;

    ll n_pow = 1LL;
    for (ll i = 1; i <= n; i++) (n_pow *= i) %= MOD;

    ll sm[n];
    sm[0] = 0;
    for (ll i = 1; i < n; i++) {
        sm[i] = n_pow * pow_mod(i+1, MOD-2) % MOD;
        (sm[i] += sm[i-1]) %= MOD;
    }

    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> a;
        (ans += n_pow * a % MOD) %= MOD;
        (ans += (sm[i] + sm[n-i-1]) % MOD * a % MOD) %= MOD;
    }

    cout << ans << "\n";
    return 0;
}