#ifndef ___CLASS_MODINT
#define ___CLASS_MODINT

#include <cstdint>

template<std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::uint64_t n_) : n(n_ % mod) {};
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	std::uint32_t get() const { return n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint binpow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
	modint inv() { return (*this).binpow(mod - 2); }
};

#endif // ___CLASS_MODINT

#include <vector>
#include <iostream>
using namespace std;
using modulo = modint<1000000007>;
long long tenpow(int X) {
	return X == 0 ? 1 : tenpow(X - 1) * 10;
}
const int first_lim = 7;
int main() {
	int N;
	cin >> N;
	int primary_lim = tenpow(first_lim);
	int second_lim = primary_lim + N / (first_lim + 1) + 2;
	vector<long long> SEQ(second_lim);
	long long mul = 1;
	for (int i = 1; i <= first_lim + 1; ++i) {
		for (int j = mul; j < mul * 10 && j < second_lim; ++j) {
			SEQ[j] = i;
		}
		mul *= 10;
	}
	modulo ans = 0;
	int r = 1, s = 0;
	for (int i = 1; i < primary_lim; ++i) {
		while (s < N) s += SEQ[r++];
		if (s == N) ans += 1;
		s -= SEQ[i];
	}
	for (int i = 2; i <= N; ++i) {
		if (N % i == 0) continue;
		if (N / i <= first_lim) break;
		ans += 1;
	}
	for (int i = first_lim + 1; i <= N / 2; ++i) {
		if (N % i == 0) {
			ans += modulo(10).binpow(i - 1) * 9 - modulo(N / i) + 1;
		}
	}
	if (N >= first_lim + 1) ans += modulo(10).binpow(N - 1) * 9;
	cout << ans.get() << endl;
	return 0;
}