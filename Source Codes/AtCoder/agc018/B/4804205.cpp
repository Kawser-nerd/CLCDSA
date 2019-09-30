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

const int MAX_N = 300, MAX_M = 300;
int N, M;
int A[MAX_N][MAX_M];
bool used[MAX_M];
int sum[MAX_M];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> M;
  rep(i, N) {
      rep(j, M) {
          cin >> A[i][j];
          --A[i][j];
      }
  }


  if (M == 1) {
      cout << N << endl;
      return 0;
  }

  ll ans = INFINT;
  memset(used, true, sizeof(used));
  for (int n = 0; n < M-1; ++n) {
      memset(sum, 0, sizeof(sum));
      for (int i = 0; i < N; ++i) {
          for (int j = 0; j < M; ++j) {
              if (used[A[i][j]]) {
                  ++sum[A[i][j]];
                  break;
              }
          }
      }

      ll ma = 0, sport = 0;
      for (int i = 0; i < M; ++i) {
          if (ma < sum[i]) {
              ma = sum[i]; sport = i;
          }
      }
      ans = min(ans, ma);
      used[sport] = false;
  }


  cout << ans << endl;
  
  return 0;
}