// Last Change: 02/18/2019 18:47:38.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

const int INF = 105;

int main() {
  int N, NGF, NGS, NGT;
  cin >> N >> NGF >> NGS >> NGT;

  if (N == NGF || N == NGS || N == NGT) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> dp(N + 1);
  dp[0] = INF;
  dp[1] = dp[2] = dp[3] = 1;
  for (int i = 4; i < N + 1; ++i) {
    if (i == NGF || i == NGS || i == NGT) {
      dp[i] = INF;
    } else {
      dp[i] = min(dp[i - 1] + 1, dp[i - 2] + 1);
      dp[i] = min(dp[i], dp[i - 3] + 1);
    }
  }

  string ans = "YES";
  if (dp[N] == INF) {
    ans = "NO";
  }
  if (dp[N] > 100) {
    ans = "NO";
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}