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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int N, M;

//x^n?mod????????
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow((x*x) % mod, n/2, mod);
  if (n & 1) res = (res*x) % mod;
  return res;
}

ll my_pow(ll x, ll n) {
  if (n == 0) return 1;
  ll res = pow(x*x, n/2);
  if (n & 1) res *= x;
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> M;

  cout << my_pow(2, M) * 100 * (N + 18*M) << endl;
}