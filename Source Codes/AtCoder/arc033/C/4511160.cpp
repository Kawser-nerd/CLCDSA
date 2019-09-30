#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using vv = vector<vector<ll>>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end());
#define MIN(vec) *std::min_element(vec.begin(), vec.end());
#define BIT(n, num) std::bitset<(n)>((num)).to_string()
#define REV(T) greater<T>()
#define PQ priority_queue<ll, vector<ll>, greater<ll>>

typedef pair<ll, ll> Pair;
bool pairCompare(const Pair &firstElof, const Pair &secondElof) {
  return firstElof.second > secondElof.second;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename Monoid> struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;

  ll sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M1;

  SegmentTree(ll n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(ll k, const Monoid &x) { seg[k + sz] = x; }

  void build() {
    for (ll k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(ll k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while (k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(ll a, ll b) {
    Monoid L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if (a & 1)
        L = f(L, seg[a++]);
      if (b & 1)
        R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const ll &k) const { return seg[k + sz]; }
};

int main() {
  ll Q;
  vector<ll> T, X;
  cin >> Q;
  SegmentTree<ll> seg(200001, [](ll a, ll b) { return a + b; }, 0);
  REP(i, Q) {
    ll t, x;
    cin >> t >> x;
    T.push_back(t);
    X.push_back(x);
  }
  REP(i, Q) {
    if (T[i] == 1) {
      seg.update(X[i], seg[X[i]] + 1);
    } else {
      ll left = -1;
      ll right = 200001;
      while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        ll num = seg.query(0, mid + 1);
        if (num >= X[i])
          right = mid;
        else
          left = mid;
      }
      cout << right << endl;
      seg.update(right, seg[right] - 1);
    }
  }
  return 0;
}