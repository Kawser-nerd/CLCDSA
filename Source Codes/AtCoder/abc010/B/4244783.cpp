// Last Change: 02/12/2019 19:56:16.
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
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    while (1) {
      ll lastAns = ans;
      if (a % 2 == 0) {
        --a;
        ++ans;
      }
      if (a % 3 == 2) {
        --a;
        ++ans;
      }
      if (lastAns == ans) {
        break;
      }
    }
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}