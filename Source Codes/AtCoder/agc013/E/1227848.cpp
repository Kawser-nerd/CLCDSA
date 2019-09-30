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
// {{{ Modular arithmetic

ll ifloor(ll, ll);
ll iceil(ll a, ll b) {
  assert(b != 0);
  if (b < 0) { b = -b; a = -a; }
  if (a < 0) return -ifloor(-a, b);
  return (a + b - 1) / b;
}
ll ifloor(ll a, ll b) {
  assert(b != 0);
  if (b < 0) { b = -b; a = -a; }
  if (a < 0) return -iceil(-a, b);
  return a / b;
}
ll imod(ll a, ll b) {
  assert(b != 0);
  return a - b * ifloor(a, b);
}

// }}}
// {{{ Solver

const ll MOD = ll(1e9)+7;

typedef array<ll,3> Vec;
typedef array<ll,9> Mat;

template <int N>
array<ll,N> matmul(array<ll,N*N> A, array<ll,N> x) {
  // row-major
  array<ll,N> y = {{0,0,0}};
  Loop(i,N) Loop(j,N) y[i] += A[N*i+j] * x[j] % MOD;
  Loop(i,N) y[i] = imod(y[i], MOD);
  return y;
}

template <int N>
array<ll,N*N> matmul(array<ll,N*N> A, array<ll,N*N> B) {
  // row-major
  array<ll,N*N> C = {{0,0,0, 0,0,0, 0,0,0}};
  Loop(i,N) Loop(j,N) Loop(k,N) C[N*i+k] += A[N*i+j] * B[N*j+k] % MOD;
  Loop(i,N) Loop(j,N) C[N*i+j] = imod(C[N*i+j], MOD);
  return C;
}

Vec evalFree2(ll n, Vec a) {
  assert(n >= 0);
  Mat A = {{4, -2, 1, 1, 0, 0, 0, 1, 0}};
  for (ll i = 1, x = n; x != 0; i *= 2) {
    if (x & i) {
      x -= i;
      a = matmul<3>(A, a);
    }
    A = matmul<3>(A, A);
  }
  return a;
}

ll evalFree(ll n) {
  Vec a = evalFree2(n, Vec{{0,1,3}});
  return a[0];
}

#ifdef ONLINE_JUDGE
void solve(ostream& rout) {
  std::ios::sync_with_stdio(false); cin.tie(nullptr);
#else
void solve(outboth rout) {
#endif

  assert(evalFree(0) == 0);
  assert(evalFree(1) == 1);
  assert(evalFree(4) == 63);
  assert(evalFree(5) == 221);
  assert(evalFree(20) == 639429922ll);

  int N, M; cin >> N >> M; if (!cin) return;
  Vll X(M); read(X);
  // dout << db(N) << db(M) << show(X) << endl;

  // Vll Y = X; Y.insert(Y.begin(), 0ll); push(Y, ll(N));
  // Vll dp(M+2, 0);
  // Loop(i,sz(Y)) {
  //   dp[i] = evalFree(Y[i]);
  //   Vec a = Vec{{0,1,3}};
  //   ll yprev = Y[i];
  //   for (int j = i-1; j >= 0; --j) {
  //     a = evalFree2(yprev - Y[j], a);
  //     // dp[i] += MOD - evalFree(Y[i] - Y[j]) * dp[j] % MOD;
  //     dp[i] += MOD - a[0] * dp[j] % MOD;
  //     yprev = Y[j];
  //   }
  //   dp[i] %= MOD;
  // }
  // rout << dp[M+1] << endl;

  Vec a = {{0,1,3}}, a1 = {{0,1,3}};
  ll xprev = 0;
  for (ll x : X) {
    a = evalFree2(x - xprev, a);
    // dout << db(x) << show(a) << endl;
    ll w = a[0];
    Loop(i,3) a[i] = (a[i] + MOD - w * a1[i] % MOD) % MOD;
    // dout << db(x) << show(a) << endl;
    xprev = x;
  }
  a = evalFree2(N - xprev, a);
  rout << a[0] << endl;

  // // Working!
  // dout << db(evalFree(N)) << endl;
  // ll ans = 0;
  // for (int s = 0; s < (1<<sz(X)); ++s) {
  //   Vll Y; Loop(i,sz(X)) if (s&(1<<i)) push(Y, X[i]);
  //   ll yprev = 0, sofar = 1;
  //   bool odd = false;
  //   for (ll y : Y) {
  //     odd = !odd;
  //     sofar = sofar * evalFree(y - yprev) % MOD;
  //     yprev = y;
  //   }
  //   sofar = sofar * evalFree(N - yprev) % MOD;
  //   ans += (odd ? -1 : +1) * sofar;
  // }
  // ans = imod(ans, MOD);
  // rout << ans << endl;

  // rout << evalFree(N) << endl;
}

// }}}
// {{{ Main
int main() {
  solve(cout);
  return 0;
}
// }}}