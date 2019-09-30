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

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp) % MOD;
  } else {
    return (n * POW(n, m - 1)) % MOD;
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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

void shortestPath(const Graph &g, ll s, vector<Weight> &dist,
                  vector<ll> &prev) {
  ll n = g.size();
  dist.assign(n, llINF);
  dist[s] = 0;
  prev.assign(n, -1);
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty();) {
    Edge e = Q.top();
    Q.pop();
    if (prev[e.dst] != -1)
      continue;
    prev[e.dst] = e.src;
    AUTO(f, g[e.dst]) {
      if (dist[f.dst] > e.weight + f.weight) {
        dist[f.dst] = e.weight + f.weight;
        Q.push(Edge(f.src, f.dst, e.weight + f.weight));
      }
    }
  }
}
vector<ll> buildPath(const vector<ll> &prev, ll t) {
  vector<ll> path;
  for (ll u = t; u >= 0; u = prev[u])
    path.push_back(u);
  reverse(path.begin(), path.end());
  return path;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M, T;
  cin >> N >> M >> T;
  vector<ll> A(N, 0);

  Graph G1(N, Edges());
  vector<ll> dist1(N, 0);
  vector<ll> prev1(N, 0);
  Graph G2(N, Edges());
  vector<ll> dist2(N, 0);
  vector<ll> prev2(N, 0);

  REP(i, N) cin >> A[i];
  REP(i, M) {
    ll a, b, c;
    cin >> a >> b >> c;
    G1[a - 1].push_back(Edge(a - 1, b - 1, c));
    G2[b - 1].push_back(Edge(b - 1, a - 1, c));
  }
  shortestPath(G1, 0, dist1, prev1);
  shortestPath(G2, 0, dist2, prev2);

  ll ans = 0;
  REP(i, N) {
    if (T > dist1[i] + dist2[i]) {
      ll score = (T - dist1[i] - dist2[i]) * A[i];
      if (ans < score)
        ans = score;
    }
  }
  cout << ans << endl;

  return 0;
}