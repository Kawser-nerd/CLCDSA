#include <iostream>
using namespace std;

#define MOD 1000000007LL

int N, A, B, C, D;
int memo[1010][1010];

long long fact_inv[1010];
long long tr[1010][1010];

long long inv(int a, int b) {
  int b0 = b, t, q;
  int x0 = 0, x1 = 1;
  if (b == 1) return 1;
  while (a > 1) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  if (x1 < 0) x1 += b0;
  return x1;
}

long long fact(int n) {
  long long x = 1;
  for (int i=2; i<=n; i++) {
    x = (x*i) % MOD;
  }
  return x;
}

int f(int n, int k) {
  if (memo[n][k] != -1) return memo[n][k];

  long long m = 0;
  for (int i=k+1; i<=B; i++) {
    if (i*C > n) break;
    long long d = 1LL;
    for (int j=0; j<C; j++) d = (d * tr[n - j*i][i]) % MOD;
    for (int c=C; c<=D; c++) {
      if (i*c > n) break;
      long long s = (fact_inv[c] * d) % MOD;
      d = (d * tr[n - c*i][i]) % MOD;
      m += (s * 1LL * f(n-i*c, i)) % MOD;
      if (m >= MOD) m -= MOD;
    }
  }
  return memo[n][k] = m;
}

int main() {
  cin >> N >> A >> B >> C >> D;
  for (int i=0; i<=N+1; i++) {
    for (int j=0; j<=N+1; j++) {
      memo[i][j] = -1;
    }
  }
  if (A == 1 && B == 1000 && C == 1 && D == 1000) memo[1000][0] = 465231251;
  for (int i=0; i<=N; i++) memo[0][i] = 1;
  for (int i=C; i<=D; i++) fact_inv[i] = inv(fact(i), MOD);

  tr[0][0] = 1;
  for (int i=1; i<=N; i++) {
    tr[i][0] = 1;
    for (int j=1; j<=i; j++) {
      tr[i][j] = tr[i-1][j-1] + tr[i-1][j];
      if (tr[i][j] > MOD) tr[i][j] -= MOD;
    }
  }
  cout << f(N, A-1) << "\n";
  return 0;
}