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

// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size(); s << "\n";
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  s << "\n"; return s;
}

// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) { s << vv[i]; }
  return s;
}


int mod = 1e9 + 7;

// mod_power.cc
ll po(ll k, ll x) {
  if (x == 0) {
    return 1;
  }
  if (x == 1) {
    return k % mod;
  }
  ll y = po(k, x/2);
  y = y * y % mod;
  if (x % 2 == 1) {
    y = y * k % mod;
  }
  return y;
}

vll factorial;
vll inv_fact;
ll comb(ll x, ll y) {
  if (x < 0 || x < y) {
    return 0;
  }
  y = min(y, x-y);
  if (y == 0) {
    return 1;
  }
  ll ret = 1;
  ret = ret * factorial[x] % mod;
  ret = ret * inv_fact[y] % mod;
  ret = ret * inv_fact[x-y] % mod;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 3) {
    int ans = 0;
    if (n == 2) {
      ans = 1;
    } else if (n == 3) {
      ans = 4;
    }
    printf("%d\n", ans);
    return 0;
  }

  factorial.assign(n+1, 0);
  inv_fact.assign(n+1, 0);
  factorial[0] = 1;
  inv_fact[0] = 1;
  rep (i, n) {
    factorial[i+1] = factorial[i] * (i+1) % mod;
    inv_fact[i+1] = po(factorial[i+1], mod-2) % mod;
    assert(factorial[i+1] * inv_fact[i+1] % mod == 1);
  }
  ll ans = 0;
  ll prev_cnt = 0;
  FOR (i, 2, n) {
    ll cnt = 1;
    cnt = cnt * comb(i-1, n-1-i) % mod;
    cnt = cnt * factorial[i] % mod;
    cnt = cnt * factorial[n-1-i] % mod;
    ll add = (cnt + mod - prev_cnt) * i % mod;
    prev_cnt = cnt;
    ans = (ans + add) % mod;
  }

  printf("%lld\n", ans);

  return 0;
}