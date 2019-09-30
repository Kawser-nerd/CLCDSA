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
  int n, k;
  scanf("%d %d", &n, &k);
  vll orig(n, 0);
  vll altered(n, 0);
  ll sum_all = 0;
  rep (i, n) {
    scanf("%lld", &orig[i]);
    if (orig[i] > 0) {
      altered[i] = orig[i];
      sum_all += orig[i];
    }
  }
  vll sumk_orig(n-k+1, 0);
  vll sumk_altered(n-k+1, 0);
  rep (i, k) {
    sumk_orig[0] += orig[i];
    sumk_altered[0] += altered[i];
  }
  FOR (i, 1, n-k+1) {
    sumk_orig[i] = sumk_orig[i-1] - orig[i-1] + orig[i-1+k];
    sumk_altered[i] = sumk_altered[i-1] - altered[i-1] + altered[i-1+k];
  }
  ll ans = 0;

  rep (i, n-k+1) {
    ans = max(ans, sum_all - sumk_altered[i] + max(0LL, sumk_orig[i]));
  }
  printf("%lld\n", ans);

  return 0;
}