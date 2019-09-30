// Last Change: 04/09/2019 23:15:35.
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
  pair<int, int> A, B, C, D, v;

  cin >> A.first >> A.second >> B.first >> B.second;

  v.second = B.first - A.first;
  v.first = -(B.second - A.second);

  C.first = B.first + v.first;
  C.second = B.second + v.second;

  v.second = v.first;
  v.first = -(C.second - B.second);

  D.first = C.first + v.first;
  D.second = C.second + v.second;

  cout << C.first << " " << C.second << " " << D.first << " " << D.second
       << endl;

  //NS::LoopUntilZeroInpput();
}