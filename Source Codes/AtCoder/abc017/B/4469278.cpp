// Last Change: 03/04/2019 20:42:15.
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
  string X;
  cin >> X;
  int size = X.size();
  bool ans = true;
  for (int i = 0; i < size; ++i) {
    if (X[i] == 'c') {
      if (i == size - 1) {
        ans = false;
        break;
      } else {
        ++i;
        if (X[i] == 'h')
          ;
        else {
          ans = false;
          break;
        }
      }
    } else if (X[i] == 'o')
      ;
    else if (X[i] == 'k')
      ;
    else if (X[i] == 'u')
      ;
    else {
      ans = false;
      break;
    }
  }
  if (ans) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;

  //NS::LoopUntilZeroInpput();
}