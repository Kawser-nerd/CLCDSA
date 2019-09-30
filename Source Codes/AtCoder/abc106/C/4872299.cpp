// Last Change: 04/07/2019 13:32:55.
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
  string S;
  ll K;
  cin >> S >> K;

  ll onePos = 0;
  while (onePos < S.size() and S[onePos] == '1') {
    ++onePos;
  }

  if (onePos >= K) {
    cout << 1 << endl;
  } else {
    cout << S[onePos] << endl;
  }

  //NS::LoopUntilZeroInpput();
}