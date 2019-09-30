// Last Change: 03/14/2019 19:47:24.
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
  vector<int> ipt(3);
  for (int i = 0; i < 3; ++i) {
    cin >> ipt[i];
  }

  sort(ipt.begin(), ipt.end());
  cout << ipt[1] << endl;

  //NS::LoopUntilZeroInpput();
}