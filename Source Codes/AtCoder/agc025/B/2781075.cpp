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
#include <numeric>
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
#define debug(x) std::cerr<< #x <<": "<<x<<"\n"
#define debug2(x,y) std::cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<"\n"
 
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

int mod = 998244353;

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

int main() {
  int n;
  ll a, b, k;
  cin >> n >> a >> b >> k;

  vll factorial(n+1, 1);
  vll rev_fact(n+1, 1);
  FOR (i, 2, n+1) {
    factorial[i] = factorial[i-1] * i % mod;
    rev_fact[i] = po(factorial[i], mod-2) % mod;
  }

  vll comb(n+1, 0);
  rep (i, n+1) {
    comb[i] = factorial[n];
    comb[i] = comb[i] * rev_fact[i] % mod;
    comb[i] = comb[i] * rev_fact[n-i] % mod;
  }

  ll ans = 0;
  rep (ia, n+1) {
    ll rest = k - a * ia;
    if (rest < 0) {
      break;
    }
    if (rest % b != 0 || rest / b > n) {
      continue;
    }
    int ib = rest / b;
    ll add = comb[ia] * comb[ib] % mod;
    ans = (ans + add) % mod;
  }
  printf("%lld\n", ans);

  return 0;
}