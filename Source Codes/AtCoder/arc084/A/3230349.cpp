#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
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

const int MAX_N = 100000;
int N;
int A[MAX_N], B[MAX_N], C[MAX_N];
ll tmp[MAX_N];
ll sum[MAX_N];

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];
  sort(A, A+N);
  sort(B, B+N);
  sort(C, C+N);

  for (int i = 0; i < N; ++i) {
    tmp[i] = N - int(upper_bound(C, C+N, B[i]) - C);
  }

  sum[0] = tmp[0];
  for (int i = 1; i < N; ++i) sum[i] = sum[i-1] + tmp[i];

  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    int ub = upper_bound(B, B+N, A[i]) - B;
    if (ub == 0) ans += sum[N-1];
    else ans += sum[N-1] - sum[ub-1];
  }

  cout << ans << endl;

  return 0;
}