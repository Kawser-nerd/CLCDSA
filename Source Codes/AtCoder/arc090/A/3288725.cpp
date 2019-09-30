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

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
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

int N;
int A[2][100];
int sum[2][100];


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  rep(i, 2)rep(j, N) cin >> A[i][j];

  sum[0][0] = A[0][0];
  for (int j = 1; j < N; ++j) sum[0][j] = sum[0][j-1] + A[0][j];
  sum[1][0] = A[1][0];
  for (int j = 1; j < N; ++j) sum[1][j] = sum[1][j-1] + A[1][j];

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, sum[0][i] + sum[1][N-1] - sum[1][i] + A[1][i]);
  }

  cout << ans << endl;
  return 0;
}