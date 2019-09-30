// Last Change: 04/09/2019 22:59:05.
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
  int K;
  cin >> K;

  int odd, even;
  even = K / 2;
  odd = K - even;

  cout << even * odd << endl;

  //NS::LoopUntilZeroInpput();
}