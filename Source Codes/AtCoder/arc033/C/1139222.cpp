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
  static constexpr T identity() { return T(0); }
  T inverse(const T& element) { return -element; }
};

template<class Monoid>
class BIT {
private:
  using T = typename Monoid::T;
  Monoid op;
  const int n;
  vector<T> bit;
  vector<T> array;

  void propagate(int i,const T& x) {
    for (int j = i; j <= n; j += (j & -j)) bit[j] = op(bit[j], x);
  }

public:
  BIT(int n_) : n(n_), bit(n_ + 1, op.identity()), array(n_ + 1, op.identity()) {}
  BIT(const vector<T>& v) : n(v.size()), bit(n + 1), array(n + 1) {
    copy(begin(v), end(v), begin(array) + 1);
    for (int i = 1; i <= n; ++i) {
      set(i, v[i - 1]);
    }
  }

  void set(int i, const T& x) {
    T prev = array[i += 1];
    array[i] = x;
    propagate(i, op(x, op.inverse(prev)));
  }

  T get(int i) { return array[i + 1]; }

  T accumulate(int r) {
    T acc = op.identity();
    for (int j = r; j > 0; j -= (j & -j)) acc = op(bit[j], acc);
    return acc;
  }
};

int main() {
  int n = 200000 + 1;
  int q;
  scanf("%d", &q);
  int t, x;
  BIT<Sum> bit(n);
  rep (i, q) {
    scanf("%d %d", &t, &x);
    if (t == 1) {
      bit.set(x, 1);
      continue;
    }
    int l = 0;
    int r = n;
    int mid;
    while (r - l > 1) {
      mid = (l + r) / 2;
      int sum = bit.accumulate(mid);
      if (sum < x) {
        l = mid;
      } else {
        r = mid;
      }
    } // l is the answer
    printf("%d\n", l); // equal to r-1
    bit.set(l, 0);
  }

  return 0;
}