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
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define BIT(n, num) std::bitset<(n)>((num)).to_string()
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}
bool paircomprev(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first > b.first;
}
ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct UnionFind {
  vector<ll> data;

  UnionFind(ll sz) { data.assign(sz, -1); }

  bool unite(ll x, ll y) {
    x = root(x), y = root(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  ll root(ll k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = root(data[k]));
  }

  ll size(ll k) { return (-data[root(k)]); }

  ll same(ll a, ll b) { return root(a) == root(b); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M, Q;
  cin >> N >> M;
  vector<pll> Y(M);
  vl A(M), B(M);
  REP(i, M) {
    ll a, b, y;
    cin >> a >> b >> y;
    A[i] = a - 1;
    B[i] = b - 1;
    Y[i] = make_pair(y, i);
  }
  cin >> Q;
  vector<pll> C(Q);
  vl ANS(Q);
  vl V(Q);
  REP(i, Q) {
    ll v, w;
    cin >> v >> w;
    C[i] = make_pair(w, i);
    V[i] = v - 1;
  }
  sort(ALL(Y), paircomprev);
  sort(ALL(C), paircomprev);
  ll nowY = 0;
  auto uf = UnionFind(N);

  REP(i, Q) {
    // cout << "," << C[i].first << " " << V[C[i].second] << endl;
    for (ll j = nowY; j < M && Y[j].first > C[i].first; j++) {
      uf.unite(A[Y[j].second], B[Y[j].second]);
      // cout << Y[j].first << endl;
      nowY = j + 1;
    }
    ANS[C[i].second] = uf.size(V[C[i].second]);
  }
  REP(i, Q) cout << ANS[i] << endl;

  return 0;
}