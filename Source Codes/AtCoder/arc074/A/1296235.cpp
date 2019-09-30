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

typedef pair<ll, ll> pll;

pll min_diff(ll x, ll y) {
  ll diff = LLONG_MAX;
  if (y % 2 == 0) {
    diff = min(diff, (ll)0);
  } else {
    diff = min(diff, x);
  }
  if (x % 2 == 0) {
    diff = min(diff, (ll)0);
  } else {
    diff = min(diff, y);
  }
  return (pll){(x * y - diff) / 2, (x * y + diff) / 2};
}

int main() {
  ll h, w;
  cin >> h >> w;
  if (h % 3 == 0 || w % 3 == 0) {
    printf("0\n");
    return 0;
  }

  ll ans = LLONG_MAX;
  FOR (i, 1, h) {
    ll bottom = i * w;
    auto md = min_diff(h-i, w);
    ll mi = min(md.first, bottom);
    ll ma = max(md.second, bottom);
    ans = min(ans, ma - mi);
  }
  FOR (i, 1, w) {
    ll bottom = i * h;
    auto md = min_diff(w-i, h);
    ll mi = min(md.first, bottom);
    ll ma = max(md.second, bottom);
    ans = min(ans, ma - mi);
  }

  printf("%lld\n", ans);

  return 0;
}