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

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

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
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))

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

typedef ll Weight;
struct Edge {
  ll src, dst;
  Weight weight;
  Edge(ll src, ll dst, Weight weight) : src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
             e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

pair<Weight, Edges> Prim(const Graph &g, ll r = 0) {
  ll n = g.size();
  Edges T;
  Weight total = 0;

  vector<bool> visited(n);
  priority_queue<Edge> Q;
  Q.push(Edge(-1, r, 0));
  while (!Q.empty()) {
    Edge e = Q.top();
    Q.pop();
    if (visited[e.dst])
      continue;
    T.push_back(e);
    total += e.weight;
    visited[e.dst] = true;
    AUTO(f, g[e.dst]) if (!visited[f.dst]) Q.push(f);
  }
  return pair<Weight, Edges>(total, T);
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  vector<pll> X, Y;
  Graph G(N);
  REP(i, N) {
    ll x, y;
    cin >> x >> y;
    X.push_back(make_pair(x, i));
    Y.push_back(make_pair(y, i));
  }
  sort(ALL(X));
  sort(ALL(Y));

  REP(i, N - 1) {
    G[X[i].second].push_back(
        Edge(X[i].second, X[i + 1].second, X[i + 1].first - X[i].first));
    G[X[i + 1].second].push_back(
        Edge(X[i + 1].second, X[i].second, X[i + 1].first - X[i].first));
    G[Y[i].second].push_back(
        Edge(Y[i].second, Y[i + 1].second, Y[i + 1].first - Y[i].first));
    G[Y[i + 1].second].push_back(
        Edge(Y[i + 1].second, Y[i].second, Y[i + 1].first - Y[i].first));
  }
  auto ans = Prim(G, 0);
  cout << ans.first << endl;

  return 0;
}