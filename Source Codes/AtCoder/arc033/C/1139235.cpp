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

struct BIT {
  using T = int;
  const int n;
  vector<T> bit;

  BIT(int n_) : n(n_), bit(n_ + 1, 0) {}

  void add(int i,const T& x) {
    for (int j = i + 1; j <= n; j += (j & -j)) bit[j] += x;
  }

  T accumulate(int r) {
    T acc = 0;
    for (int j = r; j > 0; j -= (j & -j)) acc += bit[j];
    return acc;
  }
};

int main() {
  int n = 200000 + 1;
  int q;
  scanf("%d", &q);
  int t, x;
  BIT bit(n);
  rep (i, q) {
    scanf("%d %d", &t, &x);
    if (t == 1) {
      bit.add(x, 1);
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
    bit.add(l, -1);
  }

  return 0;
}