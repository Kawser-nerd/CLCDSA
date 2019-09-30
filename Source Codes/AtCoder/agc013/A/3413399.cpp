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
int A[MAX_N];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];

  int ans = 0;
  int state = 0;
  for (int i = 1; i < N; ++i) {
    if (state == 0) {
      if (A[i]-A[i-1] < 0) state = -1;
      if (A[i]-A[i-1] > 0) state = 1;
    } else {
      if ((A[i]-A[i-1])*state < 0) {
        ++ans; state = 0;
      }
    }
  }
  ++ans;

  cout << ans << endl;
  return 0;
}