// Last Change: 04/02/2019 22:11:47.
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
  string S, T;
  cin >> S >> T;

  int index = 0;
  int sSize = S.size();
  while (1) {
    if (index == sSize) {
      cout << "No" << endl;
      break;
    }

    string tmp = S.substr(index, sSize - index);
    tmp += S.substr(0, index);

    if (tmp == T) {
      cout << "Yes" << endl;
      break;
    }

    ++index;
  }

  //NS::LoopUntilZeroInpput();
}