#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

struct Edge{ int src, dest; };

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool win[256000];

void add_edge(Graph &g, int src, int dest) {
  g[src].push_back((Edge){src, dest});
}

int update(const Graph &g, vector<int> &res, int v) {
  if (win[v]) { res[v] = 1; return 1; }
  for (auto e: g[v]) {
    if (res[e.dest] == -1) {
      res[v] = 1;
      return 1;
    }
  }
  res[v] = -1;
  return 1e9;
}

void recession(const Graph &g, vector<int> &res) {
  assert(g.size() == res.size());
  int n = g.size();
  vector<vector<int>> rg(n);
  for (int i = 0; i < n; ++i)
    for (auto e: g[i]) rg[e.dest].push_back(i);
  vector<int> cnt(n);
  REP(i,n) cnt[i] = g[i].size();
  queue<int> que;
  REP(i,n) {
    if (win[i] || cnt[i] == 0) que.push(i);
    if (win[i]) res[i] = 1;
  }
  while (!que.empty()) {
    int v = que.front(); que.pop();
    int c = update(g, res, v);
    if (v == 0) return;
    for (int i: rg[v]) {
      if (cnt[i] <= 0 || res[i]) continue;
      cnt[i] -= c;
      if (cnt[i] <= 0) que.push(i);
    }
  }
}

void solve(ll N, ll M, vector<ll> X, vector<ll> A, vector<ll> B) {
  Graph g(N * 2);
  REP(i,M) {
    --A[i];
    --B[i];
    add_edge(g, A[i], B[i] + N);
    add_edge(g, A[i] + N, B[i]);
  }
  int lb = 0, ub = N;
  auto vec = X;
  sort(ALL(vec));
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    memset(win, 0, sizeof(win));
    REP(i,N) {
      if (X[i] >= vec[mid]) win[i] = 1; else win[i + N] = 1;
    }
    vector<int> res(2 * N);
    recession(g, res);
    if (res[0] == 1) lb = mid; else ub = mid;
  }
  cout << vec[lb] << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	ll M;
	scanf("%lld", &N);
	vector<ll> X(N-1+1);
	scanf("%lld", &M);
	vector<ll> A(M-1+1);
	vector<ll> B(M-1+1);
	for (int i = 0 ; i <= N-1 ; i++) {
	  scanf("%lld", &X[i]);
	}
	for (int i = 0 ; i <= M-1 ; i++) {
	  scanf("%lld", &A[i]);
	  scanf("%lld", &B[i]);
	}
	solve(N, M, X, A, B);
	return 0;
}