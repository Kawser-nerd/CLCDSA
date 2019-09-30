#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

using std::swap;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

ll pow_mod(ll x, ll n) {
    ll ans = 1;
    ll xx = x;
    for (ll m = n; m > 0; m >>= 1) {
        if (m & 1) {
            ans = ans * xx % MOD;
        }
        xx = xx * xx % MOD;
    }
    return ans;
}

ll inv_mod(ll n) {
    ll ans = pow_mod(n, MOD - 2);
    return ans;
}

ll fact_mod(ll n) {
    static vector<ll> memo(1e4, -1);
    if (memo[n] != -1) {
        return memo[n];
    }

    memo[0] = 1;
    for (ll i = 1; i < 1e4; i++) {
        memo[i] = i * memo[i - 1] % MOD;
    }

    return memo[n];
}

ll solve(ll x, ll y, ll d, ll l) {
    if (d + l > x * y) {
        return 0;
    }
    if (x <= 0 or y <= 0) {
        return 0;
    }

    ll ans = fact_mod(x * y);
    ans = ans * inv_mod(fact_mod(d)) % MOD;
    ans = ans * inv_mod(fact_mod(l)) % MOD;
    ans = ans * inv_mod(fact_mod(x * y - d - l)) % MOD;
    return ans;
}

int main() {
    ll r, c;
    cin >> r >> c;

    ll x, y;
    cin >> x >> y;

    ll d, l;
    cin >> d >> l;

    ll ans = solve(x, y, d, l);

    ans = (ans - solve(x - 1, y, d, l) + MOD) % MOD;
    ans = (ans - solve(x - 1, y, d, l) + MOD) % MOD;
    ans = (ans - solve(x, y - 1, d, l) + MOD) % MOD;
    ans = (ans - solve(x, y - 1, d, l) + MOD) % MOD;

    ans = (ans + solve(x - 2, y, d, l)) % MOD;
    ans = (ans + solve(x, y - 2, d, l)) % MOD;
    ans = (ans + solve(x - 1, y - 1, d, l)) % MOD;
    ans = (ans + solve(x - 1, y - 1, d, l)) % MOD;
    ans = (ans + solve(x - 1, y - 1, d, l)) % MOD;
    ans = (ans + solve(x - 1, y - 1, d, l)) % MOD;

    ans = (ans - solve(x - 2, y - 1, d, l) + MOD) % MOD;
    ans = (ans - solve(x - 2, y - 1, d, l) + MOD) % MOD;
    ans = (ans - solve(x - 1, y - 2, d, l) + MOD) % MOD;
    ans = (ans - solve(x - 1, y - 2, d, l) + MOD) % MOD;

    ans = (ans + solve(x - 2, y - 2, d, l)) % MOD;

    ans = ans * (r - x + 1) % MOD;
    ans = ans * (c - y + 1) % MOD;

    cout << ans << endl;

    return 0;
}