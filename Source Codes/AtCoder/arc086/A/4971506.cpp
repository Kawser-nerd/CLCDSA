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
    ll N, K;
    cin >> N >> K;
    map<ll, ll> M;
    rep (i, N) {
        ll a;
        cin >> a;
        ++M[a];
    }
    vector<pair<ll, ll>> V;
    for (auto it : M) {
        V.pb({it.snd, it.fst});
    }
    sort(all(V));
    ll k = V.size();
    ll ans = 0;
    ll i = 0;
    while (k > K) {
        ans += V[i].fst;
        ++i;
        --k;
    }
    cout << ans << endl;
}