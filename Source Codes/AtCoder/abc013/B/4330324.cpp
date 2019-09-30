// Last Change: 02/20/2019 19:11:08.
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

  if (a > b) {
    swap(a, b);
  }

  int ans = b - a;
  ans = min(ans, a + 10 - b);

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}