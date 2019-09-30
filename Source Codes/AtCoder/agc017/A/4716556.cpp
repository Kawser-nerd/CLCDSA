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

const int MAX_N = 50;
int N, P;
int A[MAX_N];
ll fact[MAX_N+1];
ll inv_fact[MAX_N+1];

//??a,b????ax + by = gcd(a,b) ??????x,y,gcd(a,b) ?????
ll extgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

//ax ? gcd(a,m) (mod m) ????x??????
ll mod_inverse(ll a, ll m) {
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x%m) % m;
}


void init(ll n, ll mod) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = (fact[i-1]*i)%mod;

  for (int i = 0; i <= n; ++i) inv_fact[i] = mod_inverse(fact[i], mod);
}

ll mod_comb(ll n, ll r, ll mod) {
  return fact[n]*inv_fact[r]%mod*inv_fact[n-r]%mod;
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> P;
  rep(i, N) cin >> A[i];
  init(N, MOD);
  ll odd = 0, even = 0;
  rep(i, N) {
      if (A[i]%2 == 0) {
          ++even;
      } else {
          ++odd;
      }
  }

  ll ans = 0;
  if (P == 0) {
      ans += pow(2ll, even);
      for (int i = 2; i <= odd; i += 2) {
          ans += pow(2ll, even) * mod_comb(odd, i, MOD);
      }
  } else {
      for (int i = 1;  i <= odd; i += 2) {
          ans += pow(2ll, even) * mod_comb(odd, i, MOD);
      }
  }

  cout << ans << endl;

  return 0;
}