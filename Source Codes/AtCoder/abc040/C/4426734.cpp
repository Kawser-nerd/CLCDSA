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

constexpr int INF = 1e9;
constexpr int MAX_N = 1e5+10;

int a[MAX_N];
int dp[MAX_N];

int main() {
  fill(dp, dp+MAX_N, INF);

  int N;
  cin >> N;
  for (int i{}; i < N; ++i) {
    cin >> a[i];
  }

  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);
  for (int i{2}; i < N; ++i) {
    chmin(dp[i], dp[i-1] + abs(a[i] - a[i-1]));
    chmin(dp[i], dp[i-2] + abs(a[i] - a[i-2]));
  }

  cout << dp[N-1] << endl;
  return 0;
}