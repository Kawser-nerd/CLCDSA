// Last Change: 03/04/2019 18:49:41.
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
  int A, B, C;
  cin >> A >> B >> C;
  bool m, p;
  m = p = false;
  if (C == A - B) {
    m = true;
  }
  if (C == A + B) {
    p = true;
  }

  if (m or p) {
    if (m and p) {
      cout << '?' << endl;
    } else {
      if (m) {
        cout << '-' << endl;
      } else {
        cout << '+' << endl;
      }
    }
  } else {
    cout << '!' << endl;
  }

  //NS::LoopUntilZeroInpput();
}