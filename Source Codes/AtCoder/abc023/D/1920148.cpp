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

bool eval(ll n, const vector<ll>& h, const vector<ll>& s, ll k) {
    vector<ll> t(n);
    for (ll i = 0; i < n; i++) {
        if (k < h[i]) {
            return false;
        }
        t[i] = (k - h[i]) / s[i];
    }

    sort(t.begin(), t.end());

    for (ll i = 0; i < n; i++) {
        if (t[i] < i) {
            return false;
        }
    }

    return true;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> h(n);
    vector<ll> s(n);
    for (ll i = 0; i < n; i++) {
        cin >> h[i] >> s[i];
    }

    // (lb, ub]
    ll lb = -1;
    ll ub = 1e18;
    while (ub - lb > 1) {
        ll mid = lb + (ub - lb) / 2;
        if (eval(n, h, s, mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    cout << ub << endl;

    return 0;
}