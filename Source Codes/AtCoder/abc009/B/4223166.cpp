// Last Change: 02/10/2019 16:32:17.
////////////////////////////////////////////////////////////////////////////
//  ??sort????
//
////////////////////////////////////////////////////////////////////////////
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
  //???
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  //???
  // sort(A.begin(), A.end(), greater<int>());
  sort(A.rbegin(), A.rend());
  int highest = A.front();
  for (auto itr = A.begin(); itr != A.end(); ++itr) {
    if (*itr != highest) {
      cout << *itr << endl;
      break;
    }
    highest = *itr;
  }

  //NS::LoopUntilZeroInpput();
}