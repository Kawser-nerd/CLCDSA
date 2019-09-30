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

ll mod = 1e9+7;

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

ll combination(ll n, ll k) {
  k = min(k, n-k);
  if (k == 0) {
    return 1;
  }
  ll ret = 1;
  FOR (i, n-k+1, n+1) {
    ret = ret * i % mod;
  }
  ll denomi = 1; // denominator
  FOR (i, 1, k+1) {
    denomi = denomi * i % mod;
  }
  ret = ret * po(denomi, mod-2) % mod; // inverse
  return ret;
}

int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);

  printf("%lld\n", combination(n-1+k, k));

  return 0;
}