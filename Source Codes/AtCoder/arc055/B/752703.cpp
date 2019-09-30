#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

double dp[1010][1010];

int main() {
  int N, K;

  cin >> N >> K;
  for(int r = N-1; r > 0; r--) {
    dp[r][0] = dp[r+1][0];
    for(int s = 1; s <= K; s++) {
      dp[r][s] = dp[r+1][s] + max(1.0/N + dp[r+1][s-1], dp[r+1][s]) / r;
    }
  }

  double result = max(1.0/N + dp[1][K-1], dp[1][K]);
  cout << result << endl;
}