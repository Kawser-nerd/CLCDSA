#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<pair<ll, ll>> as(N);

  for(auto i = 0; i < N; i++) {
    ll x;
    cin >> x;
    as[i] = make_pair(x, i);
  }
  sort(as.begin(), as.end(), greater<>());
  for (auto p : as) {
    cout << (p.second + 1) << endl;
  }

  return 0;
}