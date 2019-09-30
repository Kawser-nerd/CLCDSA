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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M;
  cin >> N >> M;
  Graph G(N);
  vector<ll> se;
  vector<bool> used(N, false);
  REP(i, N) se.push_back(i);
  REP(i, M) {
    ll l, r, d;
    cin >> l >> r >> d;
    G[l - 1].push_back(Edge(l - 1, r - 1, d));
    G[r - 1].push_back(Edge(r - 1, l - 1, -d));
  }
  if (M == 0) {
    cout << "Yes" << endl;
    return 0;
  }

  bool ok = true;
  while (se.size() > 0) {
    queue<pll> que;
    vl dp(N, llINF);
    que.push(make_pair(se[0], 0));
    while (!que.empty()) {
      pll now = que.front();
      que.pop();
      if (dp[now.first] == llINF)
        dp[now.first] = now.second;
      else if (dp[now.first] != now.second) {
        ok = false;
        break;
      }
      if (used[now.first])
        continue;
      used[now.first] = true;
      auto po = lower_bound(ALL(se), now.first);
      se.erase(po);
      AUTO(g, G[now.first]) {
        que.push(make_pair(g.dst, g.weight + now.second));
      }
    }
    if (!ok)
      break;
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}