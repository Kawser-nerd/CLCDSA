// Last Change: 04/07/2019 13:23:46.
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

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int k = 1; k <= N; k += 2) {
    int cnt = 0;
    for (int i = 1; i <= k; ++i) {
      if (k % i == 0) {
        ++cnt;
      }
    }
    if (cnt == 8) {
      ++ans;
    }
  }

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}