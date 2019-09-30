// B. 

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007;

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

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<LL> a(n);
	vector<modll> inv(n + 1), sum(n + 1, 0LL);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	modll x = 1;
	for (int i = 1; i <= n; ++i) {
		x *= i;
	}
	for (int i = 1; i <= n; ++i) {
		inv[i] = modll::modinv(i) * x;
		sum[i] = sum[i - 1] + inv[i];
	}
	modll ans = 0;
	for (int i = 0; i < n; ++i) {
		modll y = sum[i + 1] + sum[n - i] - sum[1];
		y *= a[i];
		ans += y;
	}
	cout << ans << endl;
	return 0;
}