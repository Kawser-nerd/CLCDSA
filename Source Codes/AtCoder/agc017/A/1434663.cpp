#include <iostream>
using namespace std;

typedef long long ll;
const int MAX_DP = 5005;
ll dp[MAX_DP];

int main() {
  int N, P;
  cin >> N >> P;
  fill(dp, dp+MAX_DP, 0);
  dp[0] += 1;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    for (int sum = MAX_DP-1; sum >= 0; sum--) {
      if (sum - a >= 0) {
	dp[sum] += dp[sum-a];
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < MAX_DP; i++) {
    if (i % 2 == P) {
      ans += dp[i];
    }
  }
  cout << ans << endl;
}