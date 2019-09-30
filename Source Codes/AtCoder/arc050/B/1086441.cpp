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
  //ll r, b, x, y;
  ll r, b, x, y;
  scanf("%lld %lld", &r, &b);
  scanf("%lld %lld", &x, &y);
  ll denomi = x * y - 1;
  __int128 numera1 = (__int128)y * r - b;
  __int128 numera2 = (__int128)x * b - r;
  if (numera1 <= 0) {
    printf("%lld\n", r);
    return 0;
  } else if (numera2 <= 0) {
    printf("%lld\n", b);
    return 0;
  }
  __int128 N1 = numera1 / denomi;
  ll ans = 0;
  for (ll n1 = (ll)(N1); n1 <= (ll)(N1) + 1; ++n1) {
    if (n1 < 0 || r - x * n1 < 0 || b - n1 < 0) {
      continue;
    }
    ll n2 = min(r - x * n1, (b - n1) / y);
    ans = max(ans, n1 + n2);
  }

  printf("%lld\n", ans);

  return 0;
}