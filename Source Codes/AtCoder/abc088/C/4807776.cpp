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

using ll [[maybe_unused]] = long long;
using ull [[maybe_unused]] = unsigned long long;
using ld [[maybe_unused]] = long double;

[[maybe_unused]] static constexpr int mod = (int)1e9 + 7;
[[maybe_unused]] static constexpr int inf = 100100100;
[[maybe_unused]] static constexpr ll linf = 1e18;
[[maybe_unused]] static constexpr double eps = 1e-9;
[[maybe_unused]] static constexpr double pi = 3.14159265359;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rrep(i, a) for (ll i = a; i >= 0; --i)
#define all(obj) begin(obj), end(obj)
#define rall(obj) rbegin(obj), rend(obj)
#define pb push_back
#define fst first
#define snd second

ll c[4][4];

int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    rep (w, 3) {
        rep (h, 3) {
            ll tmp;
            cin >> c[w][h];
        }
    }
    vector<ll> v;
    rep (i, 3) {
        v.pb((c[i][0] - c[i][1]) == (c[(i + 1) % 3][0] - c[(i + 1) % 3][1]));
        v.pb((c[i][1] - c[i][2]) == (c[(i + 1) % 3][1] - c[(i + 1) % 3][2]));
        v.pb((c[i][2] - c[i][0]) == (c[(i + 1) % 3][2] - c[(i + 1) % 3][0]));
        v.pb((c[0][i] - c[1][i]) == (c[0][(i + 1) % 3] - c[1][(i + 1) % 3]));
        v.pb((c[1][i] - c[2][i]) == (c[1][(i + 1) % 3] - c[2][(i + 1) % 3]));
        v.pb((c[2][i] - c[0][i]) == (c[2][(i + 1) % 3] - c[0][(i + 1) % 3]));
    }
    for (ll i : v) {
        if (i == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
} ./Main.cpp:25:12: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
using ll [[maybe_unused]] = long long;
           ^
./Main.cpp:26:13: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
using ull [[maybe_unused]] = unsigned long long;
            ^
./Main.cpp:27:12: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
using ld [[maybe_unused]] = long double;
           ^
./Main.cpp:29:3: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
[[maybe_unused]] static constexpr int mod = (int)1e9 + 7;
  ^
./Main.cpp:30:3: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
[[maybe_unused]] static constexpr int inf = 100100100;
  ^
./Main.cpp:31:3: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
[[maybe_unused]] static constexpr ll linf = 1e18;
  ^
./Main.cpp:32:3: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
[[maybe_unused]] static constexpr double eps = ...