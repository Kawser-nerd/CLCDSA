// Last Change: 02/12/2019 20:36:06.
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

double CalDist(const pair<ll, ll> &prev, const pair<ll, ll> &next) {
  double dist, x, y;
  x = next.first - prev.first;
  y = next.second - prev.second;
  dist = x * x + y * y;
  dist = pow(dist, 0.5);
  // cout << dist << " ";
  return dist;
}

int main() {
  pair<ll, ll> prev, next;
  ll T, V;
  cin >> prev.first >> prev.second >> next.first >> next.second >> T >> V;
  const double moveDist = T * V;
  ll n;
  cin >> n;

  string ans = "NO";
  for (int i = 0; i < n; ++i) {
    pair<ll, ll> input;
    cin >> input.first >> input.second;
    double dist = CalDist(input, prev) + CalDist(input, next);
    // cout << dist << endl;
    if (moveDist >= dist) {
      ans = "YES";
    }
  }

  //???
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}