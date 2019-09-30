// Last Change: 04/03/2019 21:58:43.
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
  int R;
  cin >> R;

  if (R < 1200) {
    cout << "ABC";
  } else if (R < 2800) {
    cout << "ARC";
  } else {
    cout << "AGC";
  }
  cout << endl;

  //NS::LoopUntilZeroInpput();
}