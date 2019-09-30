// Last Change: 03/27/2019 00:34:28.
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

const ll six[] = {1, 6, 36, 216, 1296, 7776, 46656, 279936};
const ll nine[] = {1, 9, 81, 729, 6561, 59049, 531441};

int main() {
  ll ipt;
  cin >> ipt;
  const ll N = ipt;

  vector<ll> dp(N + 1, INT64_MAX);
  dp[0] = 0;
  for (ll i = 1; i <= N; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (i - six[j] >= 0) {
        dp[i] = min(dp[i], dp[i - six[j]] + 1);
      }
    }
    for (int j = 1; j < 7; ++j) {
      if (i - nine[j] >= 0) {
        dp[i] = min(dp[i], dp[i - nine[j]] + 1);
      }
    }
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }

  cout << dp[N] << endl;

  //NS::LoopUntilZeroInpput();
}