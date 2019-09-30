// Last Change: 02/18/2019 23:59:07.
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

  //??????
  // pair<ll, ll> emptyPair(0, 0);
  vector<vector<pair<ll, ll>>> db(82);
  ll fullSum = 0;
  ll tmp = 0;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      tmp = i * j;
      pair<ll, ll> newPair(i, j);
      db[tmp].push_back(newPair);
      fullSum += tmp;
    }
  }

  ll suspectedNum = fullSum - N;
  int dbSize = db[suspectedNum].size();
  for (int i = 0; i < dbSize; ++i) {
    cout << db[suspectedNum][i].first << " x " << db[suspectedNum][i].second
         << endl;
  }

  //NS::LoopUntilZeroInpput();
}