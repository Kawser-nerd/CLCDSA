// {{{
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
// }}}

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

static constexpr int mod = (int)1e9 + 7;
static constexpr int inf = 100100100;
static constexpr ll linf = 1e18;
static constexpr double eps = 1e-9;
static constexpr double pi = 3.14159265359;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rrep(i, a) for (ll i = a; i >= 0; --i)
#define all(obj) begin(obj), end(obj)
#define rall(obj) rbegin(obj), rend(obj)
#define pb push_back
#define fst first
#define snd second


int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    --N;
    vector<tuple<ll, ll, ll>> v;
    rep (i, N) {
        ll c, s, f;
        cin >> c >> s >> f;
        v.pb({c, s, f});
    }
    rep (i, N) {
        ll ans = 0;
        for (ll j = i; j < N; ++j) {
            ll c, s, f;
            tie(c, s, f) = v[j];
            if (ans <= s) {
                ans = s;
            }
            if (ans % f != 0) {
                ans += (f * (ans / f + (ans % f != 0))) - ans;
            }
            ans += c;
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
}