#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define _size(X) (int)((X).size())
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 2000, MAX_M = 2000, MAX_Q = 200000;
int N, M, Q;
string S[MAX_N];
int dp[MAX_N+1][MAX_M+1];
int dp2[MAX_N+1][MAX_M+1];
int dp3[MAX_N+1][MAX_M+1];


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);
  
  cin >> N >> M >> Q;
  rep(i, N) {
      cin >> S[i];
  }

  for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
          int tmp = 0;
          if (i != 0) tmp += dp[i-1][j];
          if (j != 0) tmp += dp[i][j-1];
          if (i != 0 && j != 0) tmp -= dp[i-1][j-1];
          if (S[i-1][j-1] == '1') ++tmp;
          dp[i][j] = tmp;
      }
  }

  for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M-1; ++j) {
          int tmp = 0;
          if (i != 0) tmp += dp2[i-1][j];
          if (j != 0) tmp += dp2[i][j-1];
          if (i != 0 && j != 0) tmp -= dp2[i-1][j-1];
          if (S[i-1][j-1] == '1' && S[i-1][j] == '1') ++tmp;
          dp2[i][j] = tmp;
      }
  }

  for (int i = 1; i <= N-1; ++i) {
      for (int j = 1; j <= M; ++j) {
          int tmp = 0;
          if (i != 0) tmp += dp3[i-1][j];
          if (j != 0) tmp += dp3[i][j-1];
          if (i != 0 && j != 0) tmp -= dp3[i-1][j-1];
          if (S[i-1][j-1] == '1' && S[i][j-1] == '1') ++tmp;
          dp3[i][j] = tmp;
      }
  }

  while (Q--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      int vertex = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
      int edge = dp2[x2][y2-1] - dp2[x2][y1-1] - dp2[x1-1][y2-1] + dp2[x1-1][y1-1];
      edge += dp3[x2-1][y2] - dp3[x2-1][y1-1] - dp3[x1-1][y2] + dp3[x1-1][y1-1];

      cout << vertex - edge << endl;
  }

  return 0;
}