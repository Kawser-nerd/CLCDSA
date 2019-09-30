#include <iostream>
#define ll long long
using namespace std;
const int MOD = 1000000007;

inline int lgput(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x % 2 == 1) {
      ret = (1LL * ret * a) % MOD;
    }
    a = (1LL * a * a) % MOD;
    x /= 2;
  }
  return ret;
}

inline int inv(int a) { return lgput(a, MOD - 2); }

int factorial(int n) {
  int ret = 1;
  for (int i = 1; i <= n; i++) {
    ret = (1LL * ret * i) % MOD;
  }
  return ret;
}

int main() {
  int N;
  cin >> N;
  int A[N + 5];
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  int invsum[N + 5];
  invsum[0] = 0;
  for (int i = 1; i <= N; i++) {
    invsum[i] = (invsum[i - 1] + inv(i)) % MOD;
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    ans = (ans + 1LL * A[i] * (invsum[i] + invsum[N - i + 1] - 1) % MOD) % MOD;
  }

  ans = (1LL * ans * factorial(N)) % MOD;
  cout << ans << endl;
  return 0;
}