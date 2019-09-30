#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <functional>

using namespace std;

int dp[100000];

void to(int &x, int y) {
  x = min(x, y);
}

void solve(int K) {
  set<int, greater<int>> can;
  int t = 1;
  while (!can.count(t)) {
    can.insert(t);
    t *= 10;
    t %= K;
  }

  if (can.size() <= 2000) {
    for (int i = 0; i < K; i++) {
      dp[i] = 1e9;
    }

    for (int i : can) {
      dp[i] = 1;
    }

    for (int k : can) {
      int j = k;
      for (int i = 0; i < K; i++) {
        to(dp[j], dp[i] + 1);
        j++;
        if (j >= K) j -= K;
      }
      for (int i = 0; i < K; i++) {
        to(dp[j], dp[i] + 1);
        j++;
        if (j >= K) j -= K;
      }
      for (int i = 0; i < K; i++) {
        to(dp[j], dp[i] + 1);
        j++;
        if (j >= K) j -= K;
      }
    }

    cout << dp[0] << endl;
  } else {
    static bitset<200000> dp;
    for (int i : can) {
      dp[i] = true;
    }
    for (int k = 2;; k++) {
      static bitset<200000> dp2;
      for (int i : can) {
        dp2 |= dp << i;
      }
      for (int i = K; i < K * 2; i += K) {
        if (dp2[i]) {
          cout << k << endl;
          return;
        }
      }
      dp = dp2 | (dp2 >> K);
    }
  }
}

int main() {
  int K;
  cin >> K;

  solve(K);
}