#define ONLINE_JUDGE
// {{{ Includes
#ifndef ONLINE_JUDGE
#pragma clang diagnostic warning "-Wall"
#pragma clang diagnostic warning "-Wextra"
#pragma clang diagnostic warning "-Wconversion"
#pragma clang diagnostic ignored "-Wvla"
#pragma clang diagnostic ignored "-Wvla-extension"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wsign-compare"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wunused-const-variable"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wfloat-equal" // it's fine
#pragma clang diagnostic ignored "-Wdouble-promotion" // also
#endif

#include <unordered_map>
#include <random>
#include <climits>
#include <array>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <queue>
#include <cstring>
#include <limits>
#include <chrono>
#include <unistd.h>
using namespace std;
// }}}
// {{{ Utilities
#ifdef ONLINE_JUDGE
static bool debug = false;
#else
static bool debug = true;
#endif
#define db(x) #x << "=" << (x) << " "
#define dprintf debug && printf

#define All(x) x.begin(), x.end()
#define Loop(i, n) for (int i = 0; i < int(n); ++i)
template <typename T, typename Q, typename S>
bool Bounded(const T &x, const Q &a, const S &b) { return a <= x && x <= b; }

typedef long double Real;
const Real pi = 4*atan(Real(1.0));
const Real Inf = numeric_limits<Real>::infinity();
// https://github.com/JuliaLang/julia/blob/master/base/floatfuncs.jl
Real isapprox(Real x, Real y, Real rtol = sqrt(numeric_limits<Real>::epsilon()), Real atol = Real(0.0), bool nans = false) {
  return x == y ||
    (nans && isnan(x) && isnan(y)) ||
    (isfinite(x) && isfinite(y) && abs(x - y) <= atol + rtol*max(abs(x), abs(y)));
}
typedef long long int ll;
typedef vector<Real> Vd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<bool> Vb;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

template <typename T> int sz(const T &x) { return (int)x.size(); }
template <typename T, typename Q> bool mem(const T &s, const Q &x) { return s.find(x) != s.end(); }
template <typename T> void push(vector<T>& c, const T& e) { c.push_back(e); }
template <typename T> void push(queue<T>& c, const T& e) { c.push(e); }
template <typename T> void push(set<T>& c, const T& e) { c.insert(e); }
template <typename T, typename... Args> auto emplace(vector<T>& c, Args&&... args) -> decltype(c.emplace_back(args...)) { c.emplace_back(args...); }
template <typename T, typename... Args> auto emplace(queue<T>& c, Args&&... args) -> decltype(c.emplace(args...)) { c.emplace(args...); }
template <typename T, typename... Args> auto emplace(set<T>& c, Args&&... args) -> decltype(c.emplace(args...)) { c.emplace(args...); }
template <typename T> void umin(T &x, const T &y) { x = min(x, y); }
template <typename T> void umax(T &x, const T &y) { x = max(x, y); }
template <typename T> int sign(const T &x) {
  return x == 0 ? 0 : x > 0 ? 1 : -1;
}
template <typename T> T square(const T &x) { return x * x; }
// }}}
// {{{ IO
template <typename S, typename T>
istream& operator>>(istream& in, pair<S, T>& p) { return in >> p.first >> p.second; }
template <typename T> T read() { T x; cin >> x; return x; }
template <typename T, typename I = typename T::iterator>
void read(T &cnt) { for (auto& x : cnt) cin >> x; }
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  return out << "{" << p.first << ", " << p.second << "}";
}
template <typename T> struct show_container {
  const T &container;
  show_container(const T &container_) : container(container_) {}
};
template <typename T>
ostream &operator<<(ostream &o, const show_container<T> &thing) {
  bool first = true;
  o << "{";
  for (const auto &x : thing.container) {
    if (!first)
      o << ", ";
    first = false;
    o << x;
  }
  o << "}";
  return o;
}
template <typename T> show_container<T> show(const T &container) {
  return show_container<T>(container);
}

#define dprintf debug && printf
struct dout_ { } dout;
template <typename T> dout_ &operator<<(dout_ &out, const T &thing) { if (debug) cout << thing; return out; }
dout_ &operator<<(dout_ &out, ostream &(*thing)(ostream &)) { if (debug) cout << thing; return out; }

struct outboth {
  ostream &a;
  ostream &b;
  outboth(ostream &a_, ostream &b_) : a(a_), b(b_) {}
};
template <typename T> outboth &operator<<(outboth &both, const T &thing) {
  both.a << thing;
  both.b << thing;
  return both;
}
outboth &operator<<(outboth &both, ostream &(*thing)(ostream &)) {
  both.a << thing;
  both.b << thing;
  return both;
}
// }}}
// {{{ Solver

#ifdef ONLINE_JUDGE
void solve(ostream& rout) {
  std::ios::sync_with_stdio(false); cin.tie(nullptr);
#else
void solve(outboth rout) {
#endif

  int N; cin >> N; if (!cin) return;
  vector<Pii> edges(read<int>()); read(edges);
  for (Pii& e : edges) --e.first, --e.second;
  vector<Vi> adj(N);
  for (Pii e : edges) {
    push(adj[e.first], e.second);
    push(adj[e.second], e.first);
  }
  // dout << db(N) << show(edges) << endl;
  // Loop(i,N) dout << "adj[" << i << "]: " << show(adj[i]) << endl;

  Vb marked(N);
  Vi path;
  function<void(int)> dfs = [&](int u) {
    if (marked[u]) return;
    push(path, u);
    marked[u] = true;
    for (int v : adj[u]) {
      if (!marked[v]) {
        dfs(v);
        break;
      }
    }
  };

  dfs(0);
  // dout << "path(0): " << show(path) << endl;
  reverse(All(path));
  for (int u : adj[0]) {
    if (!marked[u]) {
      dfs(u);
      break;
    }
  }
  // dout << "path(1): " << show(path) << endl;

  rout << sz(path) << "\n";
  Loop(i,sz(path)) rout << (i == 0 ? "" : " ") << (1+path[i]);
  rout << endl;
}

// }}}
// {{{ Main
int main() {
  solve(cout);
  return 0;
}
// }}}