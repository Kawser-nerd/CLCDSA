// Last Change: 03/29/2019 13:35:59.
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

  ll cnt = 0;
  ll tmpN = N;
  while (tmpN > 0) {
    cnt += tmpN % 10;
    tmpN /= 10;
  }

  if (N % cnt == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  //NS::LoopUntilZeroInpput();
}