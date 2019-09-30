// Last Change: 03/28/2019 18:19:45.
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
  int D, N;
  cin >> D >> N;

  ll ans = N;
  if (N == 100) {
    ++ans;
  }
  for (int i = 0; i < D; ++i) {
    ans *= 100;
  }

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}