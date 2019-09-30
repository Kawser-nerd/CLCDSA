// Last Change: 03/28/2019 18:39:19.
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

  ll ipt, cnt;
  for (ll i = cnt = 0; i < N; ++i) {
    cin >> ipt;
    while (ipt % 2 == 0) {
      ipt /= 2;
      ++cnt;
    }
  }

  cout << cnt << endl;

  NS::LoopUntilZeroInpput();
}