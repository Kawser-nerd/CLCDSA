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
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<i_i, int> p_i;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
template<class T> using vv=vector<vector< T > >;
typedef deque<int> di;
typedef deque<deque<int> > ddi;

int main() {
  int n, k;
  cin >> n >> k;
  if (n == k) {
    printf("1.0\n");
    return 0;
  }

  vector< vv<double> > dp(n+1, vv<double>(k+1, vector<double>(2, 0.0)));
  FOR(i,1,k+1) {
    dp[n][i][1] = 1.0;
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = min(k, n-1); j >= 0; j--) {
      double p_max = dp[i+1][j][0];
      if (j < k) {
        p_max = max(p_max, dp[i+1][j+1][1]);
      }
      rep(b,2) {
        dp[i][j][b] += p_max / (i+1);
        dp[i][j][b] += dp[i+1][j][b] * i / (i+1);
      }
    }
  }

  printf("%f\n", dp[0][0][0]);

  return 0;
}