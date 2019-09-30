/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-25 21:06:35
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

const int MAX_SIZE = 1000010;
const long long MOD = 998244353;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init() {
  inv[1] = 1;
  for (int i=2; i<MAX_SIZE; i++) {
    inv[i] = ((MOD - inv[MOD%i]) * (MOD/i))%MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<MAX_SIZE; i++) {
    fact[i] = (i * fact[i-1])%MOD;
    factinv[i] = (inv[i] * factinv[i-1])%MOD;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%MOD * factinv[n-k])%MOD;
  }
  return 0;
}

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

ll N, K;

ll catalan(ll T, ll X, ll Y)
{
  return (C((X + Y) % MOD, X) + MOD - C((X + Y) % MOD, (Y + MOD - T) % MOD)) % MOD;
}

int main() {
  init();
  cin >> N >> K;
  if (N > K)
  {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  for (ll R = 0; R <= K; R++)
  {
    ll B = K - R;
    if (R < B)
      continue;
    else if (R == B)
    {
      ans += catalan(R - N + 1, R, B - 1);
      ans %= MOD;
    }
    else if (B - R < N)
    {
      ans += catalan(R - N + 1, R, B);
      ans %= MOD;
    }
    else
    {
      ans += C(R + B, R);
      ans %= MOD;
    }
  }
  cout << ans << endl;
}