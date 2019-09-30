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

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<pair<ll, ll>> as(N);
  for (auto i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    as[i] = make_pair(a, b);
  }
  sort(as.begin(), as.end());

  ll ik = 0;
  for (auto i = 0; i < N; i++){
    ik += as[i].second;
    if (K <= ik) {
      cout << as[i].first << endl;
      break;
    }
  }

  return 0;
}