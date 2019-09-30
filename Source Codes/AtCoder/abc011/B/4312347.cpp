// Last Change: 02/18/2019 18:33:09.
///////////////////////////////////////////////////////////////////////////
//  Ascii????????
//  static_cast<Type>(var) ???
///////////////////////////////////////////////////////////////////////////

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

char ChangeSize(const char input, bool mode) {
  int ch = static_cast<int>(input);
  char ans = input;
  if (mode == 0) {
    if (ch > 91) {
      ch -= 32;
      ans = static_cast<char>(ch);
    }
  } else if (mode == 1) {
    if (ch < 91) {
      ch += 32;
      ans = static_cast<char>(ch);
    }
  }
  return ans;
}

int main() {
  string S;
  cin >> S;
  size_t size = S.size();
  for (size_t i = 0; i < size; ++i) {
    int mode = 1;
    if (i == 0) {
      mode = 0;
    }
    S[i] = ChangeSize(S[i], mode);
  }
  cout << S << endl;
  //NS::LoopUntilZeroInpput();
}