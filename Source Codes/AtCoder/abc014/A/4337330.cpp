// Last Change: 02/21/2019 16:19:23.
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
  int a, b;
  cin >> a >> b;

  ll ans;
  if (a == b) {
    ans = 0;
  } else {
    ans = a % b;
    ans = b - ans;
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}