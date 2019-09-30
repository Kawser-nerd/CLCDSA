#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define repa(X,A,Y) for (int (X) = A;(X) <= (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;

const int MAX_N = 2000;
ll N, K;
ll a[MAX_N+1];
ll dp[MAX_N+1][MAX_N+1];
ll sum[MAX_N+1];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> K;
  repa(i, 1, N) cin >> a[i];
  for (int i = 1; i <= N; ++i) sum[i] = sum[i-1]+a[i];

  if (K == sum[N]) {
    cout << 1 << endl;
    return 0;
  }

  rep(i, N+1)rep(j, N+1) dp[i][j] = INFLL;
  for (int i = 0; i <= N; ++i) dp[i][0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      ll win;
      if (j == 1) win = 1;
      else {
        if (dp[i-1][j-1] != INFLL) win = (dp[i-1][j-1]*a[i])/sum[i-1] + 1;
        else win = INFINT;
      }
      if (win+dp[i-1][j-1] > K) {
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = min(dp[i-1][j], win+dp[i-1][j-1]);
      }
    }
  }

  int ans = 0;
  for (int j = 0; j <= N; ++j) {
    if (dp[N][j] != INFLL) ans = j;
  }

  cout << ans << endl;
  return 0;
}