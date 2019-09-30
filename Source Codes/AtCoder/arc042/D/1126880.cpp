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
 
ll x, a, b;
ll mod;
 
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
  scanf("%lld %lld %lld %lld", &x, &mod, &a, &b);
  if (x == 1 || a == 0 || mod-1 <= b-a+1) {
    printf("1\n");
    return 0;
  }
  if (b-a <= 3e8) {
    ll r = po(x, a);
    ll ans = r;
    rep (i, b-a) {
      r = r * x % mod;
      ans = min(ans, r);
    }
    printf("%lld\n", ans);
    return 0;
  }
 
  return 0;
}