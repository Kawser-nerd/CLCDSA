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

template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    for (T e : v) {
        os << e << ' ';
    }
    return os;
}

vector<ll> factorize(ll n) {
    vector<ll> ans;

    ll m = n;
    for (ll i = 2; i * i <= m; i++) {
        while (m % i == 0) {
            ans.push_back(i);
            m /= i;
        }
    }

    if (m != 1) {
        ans.push_back(m);
    }

    return ans;
}

vector<ll> dividers(ll n) {
    vector<ll> ans;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// sum of { i | gcd(i, d) == 1, i \in [1, n] }
ll solve(ll n, ll d) {
    // cout << "solve(n = " << n << ", d = " << d << ")" << endl;
    vector<ll> es = factorize(d);
    es.erase(unique(es.begin(), es.end()), es.end());

    const ll m = es.size();
    ll ans = 0;
    for (ll s = 0; s < (1 << m); s++) {
        ll mul = 1;
        ll siz = 0;
        for (ll j = 0; j < m; j++) {
            if (s & (1 << j)) {
                mul *= es[j];
                siz++;
            }
        }

        ll num = mul * (n / mul) * (n / mul + 1) / 2 % MOD;
        if (siz % 2 == 0) {
            ans = (ans + num) % MOD;
        } else {
            ans = (ans - num + MOD) % MOD;
        }
    }
    // cout << ans << endl;
    return ans;
}

int main() {
    ll n, k;

    cin >> n >> k;

    ll ans = 0;
    for (ll d : dividers(k)) {
        ll v = k * solve(n / d, k / d) % MOD;
        ans = (ans + v) % MOD;
    }

    cout << ans << endl;

    return 0;
}