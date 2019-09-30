// Last Change: 04/07/2019 13:19:32.
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
  ll A, B, area, road;
  cin >> A >> B;

  area = A * B;
  road = A + B - 1;

  cout << area - road << endl;

  //NS::LoopUntilZeroInpput();
}