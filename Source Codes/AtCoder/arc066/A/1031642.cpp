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

int mod = 1e9 + 7;

ll pow_mod(int x) {
  if (x == 0) {
    return 1;
  }
  ll y = pow_mod(x / 2);
  y = (y * y) % mod;
  if (x % 2 == 1) {
    y  = y * 2 % mod;
  }
  return y;
}

int main() {
  int n;
  scanf("%d", &n);
  vll a(n);
  rep (i, n) {
    scanf("%lld", &a[i]);
  }
  sort(all(a));
  if (n % 2 == 0) {
    rep (i, n) {
      int expect = i / 2 * 2 + 1;
      if (a[i] != expect) {
        printf("0\n");
        return 0;
      }
    }
    ll ans = pow_mod(n / 2);
    printf("%lld\n", ans);
    return 0;
  } else {
    if (a[0] != 0) {
      printf("0\n");
      return 0;
    }
    FOR (i, 1, n) {
      int expect = (i+1) / 2 * 2;
      if (a[i] != expect) {
        printf("0\n");
        return 0;
      }
    }
    ll ans = pow_mod(n / 2);
    printf("%lld\n", ans);
  }

  return 0;
}