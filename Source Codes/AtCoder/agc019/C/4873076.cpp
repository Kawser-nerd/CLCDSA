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

const int MAX_N = 200000;
int N;
ll xs, ys, xg, yg;
ll X[MAX_N], Y[MAX_N];
ll dp[MAX_N+1];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> xs >> ys >> xg >> yg;
  cin >> N;
  rep(i, N) cin >> X[i] >> Y[i];

  xg -= xs;
  yg -= ys;
  for (int i = 0; i < N; ++i) {
      X[i] -= xs;
      Y[i] -= ys;
  }

  if (xg < 0) {
      xg *= -1;
      for (int i = 0; i < N; ++i) {
          X[i] *= -1;
      }
  }
  if (yg < 0) {
      yg *= -1;
      for (int i = 0; i < N; ++i) {
          Y[i] *= -1;
      }
  }

  vector<Pii> vp;
  for (int i = 0; i < N; ++i) {
      if (0 <= X[i] && X[i] <= xg && 0 <= Y[i] && Y[i] <= yg) {
          vp.push_back(Pii(X[i], Y[i]));
      }
  }
  sort(all(vp));

  for (int i = 0; i < _size(vp)+1; ++i) {
      dp[i] = INFINT;
  }
  dp[0] = -1;

  for (int i = 0; i < _size(vp); ++i) {
      int idx = upper_bound(dp, dp+_size(vp)+1, vp[i].sc) - dp;
      dp[idx] = vp[i].sc;
  }

  ll K = 0;
  for (int i = 1; i < _size(vp)+1; ++i) {
      if (dp[i] < INFINT) {
          ++K;
      } else {
          break;
      }
  }

  ll s = xg + yg;
  ll q, p;
  if (K < min(xg, yg) + 1) {
      q = K;
      p = 0;
  } else {
      q = K-1;
      p = 1;
  }

  printf("%.15lf\n", 100.0*s - (20.0 - 5.0*M_PI)*q - (20.0 - 10.0*M_PI)*p);
  return 0;
}