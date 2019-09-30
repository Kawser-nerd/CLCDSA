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
int A[MAX_N+1];
ll prob[MAX_N+1];
ll fact[MAX_N+1];
ll probs[MAX_N+1];

//??a,b????ax + by = gcd(a,b) ??????x,y,gcd(a,b) ?????
int extgcd(int a, int b, int& x, int& y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

//ax ? gcd(a,m) (mod m) ????x??????
int mod_inverse(int a, int m) {
  int x, y;
  extgcd(a, m, x, y);
  return (m + x%m) % m;
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i];


  fact[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fact[i] = mod(fact[i-1]*i, MOD);
  }
  for (int i = 1; i <= N; ++i) {
    prob[i] = mod_inverse(i, MOD);
  }
  for (int i = 1; i <= N; ++i) {
    probs[i] = mod(probs[i-1]+prob[i], MOD);
  }

  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    ll t = mod(probs[i]+probs[N-i+1]-prob[1], MOD);
    ans = mod(ans+(t*A[i])%MOD, MOD);
  }

  ans = mod(ans*fact[N], MOD);
  cout << ans << endl;
  return 0;
}