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
  vll a_input(7);
  rep (i, 7) {
    scanf("%lld", &a_input[i]);
  }
  ll ai, ao, aj, al;
  ai = a_input[0];
  ao = a_input[1];
  aj = a_input[3];
  al = a_input[4];

  ll ans = 0;
  ans += ao;
  ans += (ai / 2 * 2);
  ans += (aj / 2 * 2);
  ans += (al / 2 * 2);
  if (ai == 0 || aj == 0 || al == 0) {
    printf("%lld\n", ans);
    return 0;
  }

  ll ans2 = 0;
  ans2 += ao;
  ans2 += 3;
  ans2 += ((ai-1) / 2 * 2);
  ans2 += ((aj-1) / 2 * 2);
  ans2 += ((al-1) / 2 * 2);

  printf("%lld\n", max(ans, ans2));

  return 0;
}