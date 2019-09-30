// Last Change: 03/14/2019 19:54:29.
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
  string s;
  cin >> s;
  size_t sSize = s.size();

  char lastChar = s[0];
  int counter = 1;
  for (int i = 1; i < sSize; ++i) {
    if (lastChar != s[i]) {
      cout << lastChar << counter;
      lastChar = s[i];
      counter = 1;
    } else {
      ++counter;
    }
  }
  cout << lastChar << counter << endl;

  //NS::LoopUntilZeroInpput();
}