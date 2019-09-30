// Last Change: 02/21/2019 19:35:36.
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
  ll N;
  cin >> N;

  ll sumBug = 0;
  ll sumAll = 0;
  ll input;
  for (int i = 0; i < N; ++i) {
    cin >> input;
    if (input > 0) {
      ++sumAll;
      sumBug += input;
    }
  }

  if (sumAll == 0) {
    cout << 0 << endl;
  } else {
    ll ans = sumBug / sumAll;
    if ((sumBug % sumAll) != 0) {
      ++ans;
    }
    cout << ans << endl;
  }

  //NS::LoopUntilZeroInpput();
}