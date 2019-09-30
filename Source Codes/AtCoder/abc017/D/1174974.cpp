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

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vi flavor(n);
  rep (i, n) {
    scanf("%d", &flavor[i]);
    flavor[i] -= 1;
  }
  vi last_appeared(m, -1);
  int max_go_back = -1;
  vi accum(n+1, 0);
  accum[0] = 1;
  rep (i, n) {
    max_go_back = max(max_go_back, last_appeared[flavor[i]]);
    accum[i+1] = accum[i] * 2 - ((max_go_back < 0) ? 0 : accum[max_go_back]);
    while (accum[i+1] >= mod) {
      accum[i+1] -= mod;
    }
    while (accum[i+1] < 0) {
      accum[i+1] += mod;
    }
    last_appeared[flavor[i]] = i;
  }
  int ans = accum[n] - accum[n-1];
  if (ans < 0) {
    ans += mod;
  }
  printf("%d\n", ans);

  return 0;
}