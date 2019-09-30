// Last Change: 03/26/2019 23:50:37.
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
  ll a, b, diff;
  cin >> a >> b;
  diff = b - a;

  ll hight = 0;
  for (ll i = 0; i < diff; ++i) {
    hight += i;
  }

  cout << hight - a << endl;

  //NS::LoopUntilZeroInpput();
}