// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007;
static const size_t MAX_N = 100030;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

modll combination(LL n, LL r) {
	static modll fact[MAX_N + 1], inv[MAX_N + 1];
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= MAX_N; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[MAX_N] = modll::modinv(fact[MAX_N]);
		for (int i = MAX_N; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
	if (r > n) {
		return 0;
	}
	return (fact[n] * inv[r]) * inv[n - r];
}

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	int mx = sqrt(m);
	vector<int> b;
	for (int i = 2; i <= mx; ++i) {
		if ((m % i) == 0) {
			int cnt = 0;
			while ((m % i) == 0) {
				++cnt;
				m /= i;
			}
			b.push_back(cnt);
		}
	}
	if (m > 1) {
		b.push_back(1);
	}
	modll ans = 1;
	for (int x : b) {
		ans *= combination(x + n - 1, x);
	}
	cout << ans << endl;
	return 0;
}