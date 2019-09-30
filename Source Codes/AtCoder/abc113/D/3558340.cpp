#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int>> dp(H + 1, vector<int>(W, 0));
  dp[0][0] = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int k = 0; k < 1 << (W - 1); k++) {
        bool ok = true;
        for (int l = 0; l < W - 2; l++)
          if (((k >> l) & 1) && ((k >> (l + 1)) & 1))
            ok = false;

        if (ok) {
          if (1 <= j && ((k >> (j - 1)) & 1))
            dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
          else if (j <= W - 2 && ((k >> j) & 1))
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
          else
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
        }
      }
    }
  }
  cout << dp[H][K - 1] << endl;
  return 0;
}