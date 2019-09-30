#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;

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

vector<ll> fact_memo(2e5 + 1, -1);
ll fact_mod(ll n) {
    if (fact_memo[n] > 0) {
        return fact_memo[n];
    }
    if (n == 0) {
        return fact_memo[0] = 1;
    }
    return fact_memo[n] = n * fact_mod(n - 1) % MOD;
}

int main() {
    int w, h;
    cin >> w >> h;
    w--;
    h--;
    ll ans = fact_mod(w + h);
    ans = ans * inv_mod(fact_mod(w)) % MOD;
    ans = ans * inv_mod(fact_mod(h)) % MOD;
    cout << ans << endl;
    return 0;
}