// Last Change: 04/02/2019 22:01:29.
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
  vector<int> A(3);

  for (int i = 0; i < 3; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int diff12 = abs(A[1] - A[0]), diff23 = abs(A[2] - A[1]);
  /*
  if (diff12 > diff23) {
    cout << diff23 << endl;
  } else {
    cout << diff12 << endl;
  }*/
  cout << diff12 + diff23 << endl;

  //NS::LoopUntilZeroInpput();
}