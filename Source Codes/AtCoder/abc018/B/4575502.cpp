// Last Change: 03/14/2019 17:15:25.
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

string S;
int N;

void Operate(int l, int r) {
  string leftSubStr, centerSubStr, rightSubStr, newS;
  leftSubStr = S.substr(0, l - 1);
  centerSubStr = S.substr(l - 1, r - l + 1);
  rightSubStr = S.substr(r, S.size() - r);

  newS = leftSubStr;
  for (int i = centerSubStr.size() - 1; i >= 0; --i) {
    newS += centerSubStr[i];
  }
  newS += rightSubStr;
  S = newS;
}

int main() {
  cin >> S >> N;
  int l, r;
  for (int i = 0; i < N; ++i) {
    cin >> l >> r;
    Operate(l, r);
  }

  cout << S << endl;

  //NS::LoopUntilZeroInpput();
}