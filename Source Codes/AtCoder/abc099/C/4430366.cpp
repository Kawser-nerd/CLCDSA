#include <iostream>
using namespace std;

template<class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

constexpr int INF = 1e5 + 10;

int main() {
  int N;
  cin >> N;
  int dp[N + 2];
  fill(dp, dp + N + 2, INF);

  dp[0] = 0;
  for (int i{0}; i <= N; ++i) {
    chmin(dp[i + 1], dp[i] + 1);
    for (int p{1}; i + p <= N; p *= 6) {
      chmin(dp[i + p], dp[i] + 1);
    }
    for (int p{1}; i + p <= N; p *= 9) {
      chmin(dp[i + p], dp[i] + 1);
    }
  }

  cout << dp[N] << endl;
  return 0;
}