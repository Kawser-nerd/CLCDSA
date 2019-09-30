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
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define repa(X,A,Y) for (int (X) = A;(X) <= (Y);++(X))
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
ll A[MAX_N];
ll sum[MAX_N];


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N; rep(i, N) cin >> A[i];
  sort(A, A+N);
  sum[0] = A[0];
  for (int i = 1; i < N; ++i) sum[i] = sum[i-1] + A[i];

  int ans = 1;
  for (int i = N-2; i >= 0; --i) {
    if (sum[i]*2 >= A[i+1]) ++ans;
    else break;
  }

  cout << ans << endl;
  return 0;
}