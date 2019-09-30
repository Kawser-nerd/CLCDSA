#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;

lli pow(lli x, lli y, lli m) {
  x %= m;
  lli res = 1;
  while (y > 0) {
    if ((y & 1) == 1) {
      res = res * x % m;
    }
    x = x * x % m;
    y >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  lli m = 1000000007;
  lli n;
  string s;
  cin >> n >> s;
  lli ls = s.size();
  vector<vector<lli>> dp(n+1, vector<lli>(n+1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == 0) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % m;
      } else if (j < n) {
        dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1] * 2) % m;
      } else {
        dp[i][j] = dp[i-1][j-1] * 2 % m;
      }
    }
  }
  lli res = dp[n][ls] * pow(2, (m-2)*ls, m) % m;
  cout << res << endl;
  return 0;
}