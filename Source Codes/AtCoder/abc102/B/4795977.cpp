// Last Change: 04/01/2019 19:20:53.
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
  int N;
  cin >> N;

  ll minNum = 1000000009, maxNum = 0;
  ll ipt;
  for (int i = 0; i < N; ++i) {
    cin >> ipt;
    minNum = min(minNum, ipt);
    maxNum = max(maxNum, ipt);
  }

  cout << maxNum - minNum << endl;

  //NS::LoopUntilZeroInpput();
}