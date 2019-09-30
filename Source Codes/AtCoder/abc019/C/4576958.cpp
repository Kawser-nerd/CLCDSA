// Last Change: 03/14/2019 20:09:08.
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

ll N;
vector<ll> a;

ll GetOdd(ll ipt) {
  while (ipt % 2 == 0) {
    ipt /= 2;
  }
  return ipt;
}

int main() {
  cin >> N;
  a.resize(N);

  ll ipt;
  for (int i = 0; i < N; ++i) {
    cin >> ipt;
    a[i] = GetOdd(ipt);
  }

  sort(a.begin(), a.end());

  ll lastNum = a[0];
  ll ans = 1;
  for (ll i = 1; i < N; ++i) {
    if (lastNum != a[i]) {
      ++ans;
      lastNum = a[i];
    }
  }

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}