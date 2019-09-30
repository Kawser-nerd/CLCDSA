// Last Change: 02/21/2019 17:15:37.
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
  const ll color = 1000002;
  int n;
  vector<ll> survey(color, 0);
  cin >> n;

  ll a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    ++survey[a];
    ++b;
    --survey[b];
  }

  ll cur = 0;
  pair<ll, ll> maximum;
  maximum.first = cur;
  for (ll i = 0; i < color; ++i) {
    cur += survey[i];
    if (maximum.first < cur) {
      maximum.first = cur;
      maximum.second = i;
    }
  }

  cout << maximum.first << endl;

  //NS::LoopUntilZeroInpput();
}