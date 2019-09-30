#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 50;
int N, A;
int x[MAX_N+1];
ll dp[MAX_N+1][MAX_N+1][MAX_N*MAX_N+1];

int main() {
  cin >> N >> A;
  for (int i = 1; i <= N; ++i) cin >> x[i];

  ll sum = 0;
  for (int i = 1; i <= N; ++i) sum += x[i];
  for (int i = 0; i <= N; ++i) dp[i][0][0] = 1;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 0; k <= sum; ++k) {
        dp[i][j][k] = dp[i-1][j][k];
        if (k >= x[i]) dp[i][j][k] += dp[i-1][j-1][k-x[i]];
      }
    }
  }

  ll ans = 0;
  for (int j = 1; j <= N; ++j) {
    ans += dp[N][j][j*A];
  }

  cout << ans << endl;

  return 0;
}