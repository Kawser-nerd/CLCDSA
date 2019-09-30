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
const ll INF = 1e18;

int main() {
    ll n, h;
    cin >> n >> h;

    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if (h - n * e > 0) {
        cout << 0 << endl;
        return 0;
    }
    const ll m = -(h - n * e);
    const ll c0 = a;
    const ll v0 = e + b;
    const ll c1 = c;
    const ll v1 = e + d;

    ll ans = INF;
    for (ll i = 0; i <= n; i++) {
        ll rest_m = m - v0 * i;
        if (rest_m < 0) {
            ans = min(ans, c0 * i);
            continue;
        }
        ll j = 1 + rest_m / v1;
        if (i + j > n) {
            continue;
        }
        ans = min(ans, c0 * i + c1 * j);
    }

    cout << ans << endl;

    return 0;
}