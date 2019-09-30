// Last Change: 04/13/2019 23:34:31.
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
  int N;
  cin >> N;

  bool ans = true;
  map<string, int> W;
  char last;

  for (int i = 0; i < N; ++i) {
    string ipt;
    cin >> ipt;

    if (i > 0) {
      if (ipt[0] != last) {
        ans = false;
      }
    }

    if (W[ipt] != 0) {
      ans = false;
    }
    ++W[ipt];
    last = ipt[ipt.size() - 1];
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  //NS::LoopUntilZeroInpput();
}