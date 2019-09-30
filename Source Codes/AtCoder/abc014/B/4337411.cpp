// Last Change: 02/21/2019 16:28:52.
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
  ll n, X, ans, ipt;
  cin >> n >> X;
  ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> ipt;
    if (X & (1 << i)) {
      ans += ipt;
    }
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}