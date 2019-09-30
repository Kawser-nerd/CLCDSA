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

int main() {
  int max_w, n, max_pic;
  scanf("%d %d %d", &max_w, &n, &max_pic);
  vi width(n), value(n);
  rep (i, n) {
    scanf("%d %d", &width[i], &value[i]);
  }

  vector<vvi> dp(n+1, vvi(max_pic+1, vi(max_w+1, -1)));
  dp[0][0][0] = 0;
  rep (i, n) {
    rep (j, max_pic+1) {
      rep (k, max_w+1) {
        if (dp[i][j][k] < 0) {
          continue;
        }
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
        int i_ = i+1;
        int j_ = j+1;
        int k_ = k+width[i];
        if (j_ <= max_pic && k_ <= max_w) {
          dp[i_][j_][k_] = max(dp[i_][j_][k_], dp[i][j][k] + value[i]);
        }
      }
    }
  }
  int ans = 0;
  rep (j, max_pic+1) {
    rep (k, max_w+1) {
      ans = max(ans, dp[n][j][k]);
    }
  }
  printf("%d\n", ans);

  return 0;
}