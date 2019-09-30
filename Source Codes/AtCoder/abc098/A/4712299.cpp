// Last Change: 03/25/2019 22:56:26.
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
  ll A, B, ans;
  ans = INT64_MIN;
  cin >> A >> B;
  ans = max(ans, A + B);
  ans = max(ans, A - B);
  ans = max(ans, A * B);

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}