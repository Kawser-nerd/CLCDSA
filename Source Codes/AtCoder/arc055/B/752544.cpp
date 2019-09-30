#include <stdint.h>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);
static const ll MOD = 1000000007;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout << #x << ": " << x << endl

double dp[1024][1024][2];

int main() {
  int N;
  int K;
  cin >> N >> K;
  dp[N][0][true] = 0;
  dp[N][0][false] = 0;
  FOR(j, 1, K + 1) {
    dp[N][j][true] = 1;
    dp[N][j][false] = 0;
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = K; j >= 0; j--) {
      double p = 1.0 / (i + 1);
      dp[i][j][true] = (1 - p) * dp[i + 1][j][true]
          + p * std::max(dp[i + 1][j + 1][true], dp[i + 1][j][false]);
      dp[i][j][false] = (1 - p) * dp[i + 1][j][false]
          + p * std::max(dp[i + 1][j + 1][true], dp[i + 1][j][false]);
    }
  }
  printf("%0.12f\n", dp[0][0][false]);
}