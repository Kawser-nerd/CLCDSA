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

int main() {
  vi a = {1, 2, 4, 8};
  vi ar = {8, 4, 2, 1};
  vll price(4);
  rep (i, 4) {
    cin >> price[i];
  }
  ll n;
  cin >> n;
  n *= 4;

  vector<pair<int, int> > vp(4);
  rep (i, 4) {
    vp[i].first = price[i] * ar[i];
    vp[i].second = i;
  }
  sort(all(vp), [](auto x, auto y) {
      if (x.first == y.first) {
      return x.second >= y.second;
      }
      return x.first < y.first;
      });

  ll ans = 0;
  rep (i, 4) {
    auto b = vp[i];
    int ii = b.second;
    ll kosuu = n / a[ii];
    ans += (ll)price[ii] * kosuu;
    n -= a[ii] * kosuu;
  }
  printf("%lld\n", ans);

  return 0;
}