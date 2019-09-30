#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

int main() {
  ll n;
  scanf("%lld", &n);
  vll a(n);
  vvll positive;
  positive.reserve(n);
  ll current_max = 0;
  set<int> indexes;
  rep (i, n) {
    scanf("%lld", &a[i]);
    if (current_max < a[i]) {
      positive.push_back((vll){a[i], (ll)i});
      indexes.insert(i);
      current_max = a[i];
    }
  }
  int sz = (int)positive.size();

  vvll column_total(sz, vll(2, (ll)0));
  vll ans(n, (ll)0);
  for (int i = n-1; i >= 0; --i) {
    int lb = lower_bound(all(positive), (vll){a[i]}) - begin(positive);
    if (indexes.find(i) == end(indexes)) {
      column_total[lb][0] += 1;
      column_total[lb][1] += a[i];
    } else if (lb > 0) {
      column_total[lb][0] += 1;
      column_total[lb][1] += a[i];
      ans[positive[lb][1]] = column_total[lb][1] - column_total[lb][0] * positive[lb-1][0];
      column_total[lb-1][0] += column_total[lb][0];
      column_total[lb-1][1] += column_total[lb][0] * positive[lb-1][0];
    } else {
      ans[0] = column_total[0][1] + a[0];
    }
  }
  rep (i, n) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}