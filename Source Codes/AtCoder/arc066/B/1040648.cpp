#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int MAX_M = 70;
ll N;
ll dp[MAX_M][3];

ll memo(int digit, int val) {
  if (digit < 0) {
    return 1;
  }
  ll &res = dp[digit][val];
  if (res >= 0) {
    return res;
  }
  res = 0;
  int next_val;
  // 0 0
  next_val = 2 * val + (N >> digit & 1);
  if (next_val >= 0) {
    res += memo(digit - 1, min(2, next_val));
    res %= MOD;
  }
  //(1, 0), (0, 1)
  next_val = 2 * val + (N >> digit & 1) - 1;
  if (next_val >= 0) {
    res += memo(digit - 1, min(2, next_val));
    res %= MOD;
  }
  //(1, 1)
  next_val = 2 * val + (N >> digit & 1) - 2;
  if (next_val >= 0) {
    res += memo(digit - 1, min(2, next_val));
    res %= MOD;
  }
  return res;
}

int main(int argc, char const *argv[]) {
  cin >> N;
  memset(dp, -1, sizeof(dp));
  cout << memo(60, 0) << endl;
  return 0;
}