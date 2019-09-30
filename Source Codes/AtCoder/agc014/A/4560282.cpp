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

ll A, B, C;

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> A >> B >> C;

  int ans = 0;
  while (A%2 == 0 && B%2 == 0 && C%2 == 0) {
    ll i, j, k;
    i = (B+C)/2;
    j = (A+C)/2;
    k = (A+B)/2;
    A = i; B = j; C = k;
    ++ans;
    if ((A+B+C)%3 == 0 && A == (A+B+C)/3 && B == (A+B+C)/3 && C == (A+B+C)/3) {
      ans = -1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}