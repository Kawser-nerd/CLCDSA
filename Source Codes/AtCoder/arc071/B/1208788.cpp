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

int mod = 1e9 + 7;

vll get_coef(int k) {
  vll ret(k, 0);
  ret[0] = k;
  rep (i, k-1) {
    ret[i+1] = ret[i] + (k - (i+1) * 2);
  }
  rep (i, k) {
    ret[i] %= mod;
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vi x(n), y(m);
  rep (i, n) {
    scanf("%d", &x[i]);
  }
  rep (i, m) {
    scanf("%d", &y[i]);
  }
  sort(all(x));
  sort(all(y));
  vi dx(n-1), dy(m-1);
  rep (i, n-1) {
    dx[i] = x[i+1] - x[i];
    dx[i] %= mod;
  }
  rep (i, m-1) {
    dy[i] = y[i+1] - y[i];
    dy[i] %= mod;
  }

  vll x_coef = get_coef(n-1);
  vll y_coef = get_coef(m-1);
  ll x_sum, y_sum;
  x_sum = y_sum = 0;
  rep (i, n-1) {
    x_sum += x_coef[i] * dx[i];
    x_sum %= mod;
  }
  rep (i, m-1) {
    y_sum += y_coef[i] * dy[i];
    y_sum %= mod;
  }
  ll ans = x_sum * y_sum % mod;
  printf("%lld\n", ans);
  return 0;
}