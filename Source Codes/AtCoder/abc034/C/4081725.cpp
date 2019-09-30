#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
using int64 = int_fast64_t;
#define int int64
constexpr int MAX_N = 202020;
constexpr int MOD = 1e9 + 7;

int fact[MAX_N];
int ifact[MAX_N];

int power(int x, int n) {
	int res = 1LL;
	while (n > 0) {
		if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res % MOD;
}

int inv(int x) {
	return power(x, MOD - 2);
}

int nCr(int n, int r) {
	if (n < 0 || r < 0 || r > n) return 0;
	if (r > n / 2) r = n - r;
  //cout << fact[n] << endl;
  //cout << ifact[r] << endl;
  //cout << ifact[n-r] << endl;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

void init_fact() {
  fact[0] = ifact[0] = 1;
	for (int i=1; i<MAX_N; ++i) {
		(fact[i] = fact[i - 1] * i) %= MOD;
		ifact[i] = inv(fact[i]);
	}
}

signed main() {
  init_fact();
  int w, h;
  cin >> w >> h;
  //cout << fact[w+h] << endl;
  //cout << nCr(10, 1) << endl;
  //cout << nCr(5, 2) << endl;
  cout << (nCr(h+w-2, h-1)) << endl;
  return 0;
}