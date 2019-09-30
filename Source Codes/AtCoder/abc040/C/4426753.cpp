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
  for (int i{}; i < N; ++i) {
    chmin(dp[i+1], dp[i] + abs(a[i+1] - a[i]));
    chmin(dp[i+2], dp[i] + abs(a[i+2] - a[i]));
  }

  cout << dp[N-1] << endl;
  return 0;
}