#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
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
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define SP(a) setprecision(a)

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
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

template <typename G> struct DoublingLowestCommonAncestor {
  const ll LOG;
  vector<ll> dep; // dep[j]=h??j?????????h
  const G &g;
  // table[k][i]=p??i?2^k?????????p
  vector<vector<ll>> table;

  DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(30) {
    table.assign(LOG, vector<ll>(g.size(), -1));
  }

  void dfs(ll idx, ll par, ll d) {
    table[0][idx] = par;
    // cout << idx << "," << par << endl;
    dep[idx] = d;
    for (auto &to : g[idx]) {
      if (to != par)
        dfs(to, idx, d + 1);
    }
  }

  void build() {
    dfs(0, -1, 0);
    for (ll k = 0; k + 1 < LOG; k++) {
      for (ll i = 0; i < table[k].size(); i++) {
        if (table[k][i] == -1)
          table[k + 1][i] = -1;
        else
          table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  ll query(ll u, ll v) {
    ll inu = u, inv = v;
    if (dep[u] > dep[v])
      swap(u, v);
    for (ll i = LOG - 1; i >= 0; i--) {
      if (((dep[v] - dep[u]) >> i) & 1)
        v = table[i][v];
    }
    if (u == v)
      return dep[inu] + dep[inv] - (2 * dep[u]) + 1; // u;
    for (ll i = LOG - 1; i >= 0; i--) {
      if (table[i][u] != table[i][v]) {
        u = table[i][u];
        v = table[i][v];
      }
    }
    ll yo = table[0][u];
    return dep[inu] + dep[inv] - (2 * dep[yo]) + 1;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  ll N, Q;
  cin >> N;
  vvl G(N);
  REP(i, N - 1) {
    ll x, y;
    cin >> x >> y;
    G[x - 1].push_back(y - 1);
    G[y - 1].push_back(x - 1);
  }
  cin >> Q;
  vl A(Q, 0), B(Q, 0);
  REP(i, Q) cin >> A[i] >> B[i];

  DoublingLowestCommonAncestor<vvl> lca(G);
  lca.build();
  REP(i, Q) cout << lca.query(A[i] - 1, B[i] - 1) << endl;

  return 0;
}