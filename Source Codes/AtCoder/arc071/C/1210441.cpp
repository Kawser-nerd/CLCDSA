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

struct Sum {
  using T = int;
  T operator()(const T& left, const T& right) {
    return left + right;
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

int main() {
  string s, t;
  cin >> s;
  cin >> t;
  int sn = s.length();
  int tn = t.length();
  vi vs(sn);
  rep (i, sn) {
    if (s[i] == 'A') {
      vs[i] = 1;
    } else {
      vs[i] = -1;
    }
  }
  vi vt(tn);
  rep (i, tn) {
    if (t[i] == 'A') {
      vt[i] = 1;
    } else {
      vt[i] = -1;
    }
  }
  SegTree<Sum> segs(vs);
  SegTree<Sum> segt(vt);
  int q;
  cin >> q;
  //vi a(q), b(q), c(q), d(q);
  rep (i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a -= 1; c -= 1;
    int sums = segs.accumulate(a, b);
    int sumt = segt.accumulate(c, d);
    int diff = sums - sumt;
    if (diff < 0) diff *= (-1);
    if (diff % 3 == 0) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}