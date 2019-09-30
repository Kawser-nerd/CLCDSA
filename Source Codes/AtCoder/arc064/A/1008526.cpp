#include <algorithm>
#include <cassert>
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

int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  vi a(n);
  rep (i, n) {
    scanf("%d", &a[i]);
  }
  auto a_cp = a;

  ll ans = 0;
  rep (i, n-1) {
    if (a[i] + a[i+1] > x) {
      ll eat = a[i] + a[i+1] - x;
      if (eat <= a[i+1]) {
        a[i+1] -= eat;
        ans += eat;
      } else {
        a[i] -= (eat - a[i+1]);
        a[i+1] = 0;
        ans += eat;
      }
    }
  }
  printf("%lld\n", ans);

  return 0;
}