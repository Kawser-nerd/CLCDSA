#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

struct GCD {
  using T = int;
  T operator()(const T& l_, const T& r_) {
    T id = identity();
    T left = abs(l_), right = abs(r_);
    if (left == id && right == id) return id;
    if (left != id && right != id) return __gcd(left, right);
    else return max(left, right);
  }
  static constexpr T identity() { return T(0); }
};

template<class Monoid>
class SegTree {
private:
  using T = typename Monoid::T;
  Monoid op;
  const int n;
  vector<T> t;

  void propagate_to(int i) { t[i] = op(t[2*i], t[2*i+1]); }

public:
  SegTree(int n_) : n(n_), t(2*n, op.identity()) {}
  SegTree(const vector<T>& v) : n(v.size()), t(2*n) {
    copy(begin(v), end(v), begin(t) + n);
    for (int i = n-1; i > 0; --i) {
      propagate_to(i);
    }
  }

  void set(int i, const T& x) {
    t[i += n] = x;
    while (i >>= 1) {
      propagate_to(i);
    }
  }

  T get(int i) { return t[i + n]; }

  T accumulate(int l, int r) {
    T accl = op.identity(), accr = op.identity();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) accl = op(accl, t[l++]);
      if (r & 1) accr = op(t[r-1], accr);
    }
    return op(accl, accr);
  }
};

// ?????
template<class T_>
struct Sum {
  using T = T_;
  T operator()(const T& left, const T& right) {
    return left + right;
  }
  static constexpr T identity() { return T(0); }
};

// ?????
struct Add {
  using T = ll;
  using Monoid = Sum<ll>;
  T operator()(const Monoid::T& m, const T& a) { return m + a; }
};

template<class Action_of_Monoid>
class SegTree2 {
private:
  using T = typename Action_of_Monoid::T; // ??????????? ??:???????????????
  using M = typename Action_of_Monoid::Monoid::T; // ??????????? ??:????????????????????????
  Action_of_Monoid action; // ?????????: ?????????????????????????????
  typename Action_of_Monoid::Monoid op; // ???????????: ????????????????(???????????)
  const int n, h;
  vector<T> t;
  vector<M> deferred_action; // act(??)?????op??????
  bool has_lazy;

  void act_node(int i, const M& m) {
    if (i < n) deferred_action[i] = op(m, deferred_action[i]);
    else {
      i -= n;
      t[i] = action(m, t[i]);
    }
  }

  void propagate_from(int i) {
    act_node(i << 1, deferred_action[i]);
    act_node(i << 1 | 1, deferred_action[i]);
    deferred_action[i] = op.identity();
  }

  void propagate_to(int i) {
    i += n;
    for (int s = (i >> h ? h : h-1); s > 0; --s) propagate_from(i >> s);
  }

  int lg(int n_) {
    int h_;
    for (h_ = 0; n_ != 0; n_ >>= 1) ++h_;
    return h_ - 1;
  }

public:
  SegTree2(int n_, const T& x) : n(n_), h(lg(n)), t(n, x), deferred_action(n, op.identity()), has_lazy() {}
  SegTree2(const vector<T>& v) : n(v.size()), h(lg(n)), t(v), deferred_action(n, op.identity()), has_lazy() {}

  void act_interval(int l, int r, const M& m) {
    propagate_to(l);
    propagate_to(r-1);
    l += n, r += n;
    for ( ; l < r; l >>= 1, r >>= 1) {
      if (l & 1) act_node(l++, m);
      if (r & 1) act_node(r-1, m);
    }
    has_lazy = true;
  }

  void propagate_all() {
    for (int i = 1; i < n; ++i) propagate_from(i);
    has_lazy = false;
  }

  void set(int i, const T& x) {
    propagate_to(i);
    t[i] = x;
  }

  T get(int i) {
    if (!has_lazy) return t[i];
    T ret = t[i];
    i += n;
    while (i >>= 1) ret = action(deferred_action[i], ret);
    return ret;
  }
};


int main() {
  int n;
  scanf("%d", &n);
  vll a(n);
  rep (i, n) {
    scanf("%lld", &a[i]);
  }
  vi b(n-1);
  rep (i, n-1) {
    b[i] = a[i+1] - a[i];
  }
  SegTree<GCD> diff(b);
  SegTree2<Add> body(a);
  GCD gcd;

  int m;
  scanf("%d", &m);
  int t, l, r;
  rep (i, m) {
    scanf("%d %d %d",  &t, &l, &r);
    l -= 1; r-= 1;
    if (t != 0) {
      body.act_interval(l, r+1, t);
      if (0 < l) {
        diff.set(l-1, diff.get(l-1) + t);
      }
      if (r <= n-2) {
        diff.set(r, diff.get(r) - t);
      }
    }
    if (t == 0) {
      auto target = body.get(l);
      auto diff_gcd = diff.accumulate(l, r);
      printf("%d\n", gcd(target, diff_gcd));
    }
  }

  return 0;
}