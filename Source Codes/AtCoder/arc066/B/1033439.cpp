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
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
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
typedef pair<ll, ll> pll;

int mod = 1e9 + 7;

map<pll, bool> calculated;
map<pll, ll> f;

ll func(ll s, ll x) {
  if (s == 0) {
    return 1;
  }
  if (s == 1) {
    if (x == 0) {
      return 1;
    } else {
      return 2;
    }
  }
  if (x == 0) {
    return (1 + s / 2) % mod;
  }
  auto mpsx = mp(s, x);
  if (calculated[mpsx]) {
    return f[mpsx];
  }
  f[mpsx] = (func(s/2, x/2) + func((s-1)/2, (x-1)/2) + func((s-2)/2, x/2)) % mod;
  calculated[mpsx] = true;
  return f[mpsx];
}

int main() {
  ll n;
  scanf("%lld", &n);
  ll ans = func(n, n);
  
  printf("%lld\n", ans);
  return 0;
}