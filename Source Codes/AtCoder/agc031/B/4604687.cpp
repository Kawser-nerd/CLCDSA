#include<iostream>
#include<cstring>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  int c[n];
  int color_max = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    if (c[i] > color_max) color_max = c[i];
    if (i > 0 && c[i-1] == c[i]) {
      i--;
      n--;
    }
  }
  int dp[color_max + 1];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  dp[c[n-1]] = 1;
  for (int i = n - 2; i >= 0; i--) {
    int tmp = (dp[c[i]] + dp[0]) % 1000000007;
    dp[0] = tmp;
    dp[c[i]] = tmp;
  }
  cout << dp[0] << endl;
  return 0;
}