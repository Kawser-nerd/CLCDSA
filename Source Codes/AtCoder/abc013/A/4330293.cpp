// Last Change: 02/20/2019 19:06:14.
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
  char X;
  cin >> X;

  ll ans;
  ans = static_cast<int>(X) - static_cast<int>('A');
  ++ans;
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}