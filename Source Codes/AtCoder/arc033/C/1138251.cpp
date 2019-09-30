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
  using T = int; // type or class of monoid
  T operator()(const T& left, const T& right) {
    return left + right; // definition of operator
  }
  static constexpr T identity() { return T(0); } // ??? ???????????????
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
  int n = 200000 + 1;
  int q;
  scanf("%d", &q);
  int t, x;
  SegTree<Sum> segt(n);
  rep (i, q) {
    scanf("%d %d", &t, &x);
    if (t == 1) {
      segt.set(x, 1);
      continue;
    }
    int l = 0;
    int r = n;
    int mid;
    while (r - l > 1) {
      mid = (l + r) / 2;
      int sum = segt.accumulate(0, mid);
      if (sum < x) {
        l = mid;
      } else {
        r = mid;
      }
    } // l is the answer
    printf("%d\n", l); // equal to r-1
    segt.set(l, 0);
  }

  return 0;
}