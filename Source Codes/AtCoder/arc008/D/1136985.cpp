#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <string>
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

using L = pair<double, double>;
struct Fdpf {
  using T = L;
  T operator()(const T& left, const T& right) {
    return L(left.first * right.first, left.second * right.first + right.second);
  }
  static constexpr T identity() { return L(1, 0); }
};

template<class Monoid>
class SegTree {
public:
  using T = typename Monoid::T;
  Monoid op;
  const int n;
  vector<T> t;

  void propagate_to(int i) { t[i] = op(t[2*i], t[2*i+1]); }

  SegTree(int n_) : n(n_), t(2*n_, op.identity()) {}
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
  ll n_, m;
  scanf("%lld %lld", &n_, &m);
  map<ll, int> p_id;
  vll v_p(m, 0);
  vector<L> ab(m);
  rep (i, m) {
    scanf("%lld", &v_p[i]);
    p_id[v_p[i]] = 0;
    scanf("%lf %lf", &(ab[i].first), &(ab[i].second));
  }
  int n = (ll)p_id.size();
  {
    auto itr = p_id.begin();
    rep (i, n) {
      (*itr).second = i;
      itr ++;
    }
  }
  vi p(m, 0);
  rep (i, m) {
    p[i] = p_id[v_p[i]];
  }
  {
    int cnt = 0;
    while (n > 1) {
      n += (n & 1);
      n >>= 1;
      cnt += 1;
    }
    n = 1 << cnt;
  }

  SegTree<Fdpf> segt(n);
  double ansmin, ansmax;
  ansmin = ansmax = 1.0;
  rep (i, m) {
    segt.set(p[i], ab[i]);
    double now_1 = segt.t[1].first + segt.t[1].second;
    ansmin = min(ansmin, now_1);
    ansmax = max(ansmax, now_1);
  }
  printf("%.9f\n", ansmin);
  printf("%.9f\n", ansmax);

  return 0;
}