// Last Change: 04/02/2019 22:34:13.
/////////////////////////////////////////////////////////////////////////////
//?????????????mod????????????????????
//?????????
/////////////////////////////////////////////////////////////////////////////
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
  ll N;
  cin >> N;

  ll ans = 0, ipt;
  for (ll i = 0; i < N; ++i) {
    cin >> ipt;
    ans += ipt - 1;
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}