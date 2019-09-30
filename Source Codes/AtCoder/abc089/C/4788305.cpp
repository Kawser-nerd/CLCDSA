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


int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> M(5);
    map<char, ll> T = {
        {'M', 0},
        {'A', 1},
        {'R', 2},
        {'C', 3},
        {'H', 4}
    };
    rep (i, N) {
        string S;
        cin >> S;
        if (T.count(S[0])) {
            M[T[S[0]]] += 1;
        }
    }
    ll ans = 0;
    rep (i, 1 << 5) {
        ll tmp = 1;
        ll cnt = 0;
        rep (j, 5) {
            if ((i >> j) & 1) {
                tmp *= M[j];
                ++cnt;
            }
        }
        if (cnt == 3) {
            ans += tmp;
        }
    }
    cout << ans << endl;
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