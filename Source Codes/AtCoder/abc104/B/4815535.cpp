// Last Change: 04/03/2019 22:16:50.
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
  cin >> S;

  bool ans = true;
  int C = 0;
  const int sSize = S.size();
  for (int i = 0; i < sSize; ++i) {
    if (i == 0) {
      if (S[i] != 'A') {
        ans = false;
      }
    } else if (i >= 2 and i <= sSize - 2) {
      if (S[i] == 'C') {
        ++C;
      } else {
        if (S[i] >= 'A' and S[i] <= 'Z') {
          ans = false;
        }
      }
    } else {
      if (S[i] >= 'A' and S[i] <= 'Z') {
        ans = false;
      }
    }
  }

  if (C != 1) {
    ans = false;
  }

  if (ans) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }

  //NS::LoopUntilZeroInpput();
}