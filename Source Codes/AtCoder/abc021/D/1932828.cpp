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
    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
        ans = ans * i % MOD;
    }
    return ans;
}

int main() {
    ll n, k;
    cin >> n >> k;

    ll ans = fact_mod(n + k - 1);
    ans = ans * inv_mod(fact_mod(k)) % MOD;
    ans = ans * inv_mod(fact_mod(n - 1)) % MOD;
    cout << ans << endl;
    return 0;
}