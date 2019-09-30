#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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
int N, Z, W;
int a[MAX_N+1];
int dp[2][MAX_N+1];

int main() {
  cin >> N >> Z >> W;
  for (int i = 1; i <= N; ++i) cin >> a[i];

  for (int i = N-1; i > 0; --i) {
    int mi = INFINT, ma = -1;
    for (int j = i+1; j < N; ++j) {
      mi = min(mi, dp[1][j]);
    }
    mi = min(mi, abs(a[i]-a[N]));

    for (int j = i+1; j < N; ++j) {
      ma = max(ma, dp[0][j]);
    }
    ma = max(ma, abs(a[i]-a[N]));

    dp[0][i] = mi; dp[1][i] = ma;
  }

  int ans = 0;
  for (int i = 1; i < N; ++i) {
    ans = max(ans, dp[0][i]);
  }
  ans = max(ans, abs(W-a[N]));

  cout << ans << endl;

  return 0;
}