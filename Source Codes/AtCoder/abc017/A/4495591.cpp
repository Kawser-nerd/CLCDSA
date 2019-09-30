// Last Change: 03/04/2019 20:16:11.
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
  ll ans, s, t;
  ans = 0;
  for (int i = 0; i < 3; ++i) {
    cin >> s >> t;
    ans += s / 10 * t;
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}