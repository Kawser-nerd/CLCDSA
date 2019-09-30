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
ll N, X;
ll x[MAX_N+1];
ll sum[MAX_N+1];

ll f(ll c) {
  if (c == 1) return 5ll;
  else return 2*c+1;
}

int main() {
  cin >> N >> X;
  rep(i, 1, N) cin >> x[i];
  rep(i, 1, N) sum[i] = x[i] + sum[i-1];

  ll ans = INFLL;
  for (int k = 1; k <= N; ++k) {
    ll tmp = N*X + k*X;
    ll n = N, c = 1;
    while (n > 0) {
      ll t = f(c);
      ll ub = n, lb = (n-k >= 0 ? n-k : 0);
      ll tmp_sum = sum[ub] - sum[lb];
      if (tmp > INFLL || t * tmp_sum > INFLL) {
        tmp = INFLL; break;
      }
      tmp += t * tmp_sum;
      n = lb;
      ++c;
    }
    ans = min(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}