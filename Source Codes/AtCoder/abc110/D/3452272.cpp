#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
//#define int long long
#define double long double
#define oku7 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//?????
#define LL_HALFMAX 9223372036854775807 / 2	//?????

using namespace std;
std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x???????
int dy[4] = { 1, 0, -1, 0 }; // y???????

int x[101], y[101], h[101];

int a[2001], b[2001][2001], sum[100001];

template <signed M, unsigned T>
struct mod_int {
	constexpr static signed MODULO = M;
	constexpr static unsigned TABLE_SIZE = T;

	signed x;

	mod_int() : x(0) {}

	mod_int(long long y) : x(static_cast<signed>(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO)) {}

	mod_int(int y) : x(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO) {}

	mod_int &operator+=(const mod_int &rhs) {
		if ((x += rhs.x) >= MODULO) x -= MODULO;
		return *this;
	}

	mod_int &operator-=(const mod_int &rhs) {
		if ((x += MODULO - rhs.x) >= MODULO) x -= MODULO;
		return *this;
	}

	mod_int &operator*=(const mod_int &rhs) {
		x = static_cast<signed>(1LL * x * rhs.x % MODULO);
		return *this;
	}

	mod_int &operator/=(const mod_int &rhs) {
		x = static_cast<signed>((1LL * x * rhs.inv().x) % MODULO);
		return *this;
	}

	mod_int operator-() const { return mod_int(-x); }

	mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }

	mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }

	mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }

	mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }

	bool operator<(const mod_int &rhs) const { return x < rhs.x; }

	mod_int inv() const {
		assert(x != 0);
		if (x <= static_cast<signed>(TABLE_SIZE)) {
			if (_inv[1].x == 0) prepare();
			return _inv[x];
		}
		else {
			signed a = x, b = MODULO, u = 1, v = 0, t;
			while (b) {
				t = a / b;
				a -= t * b;
				std::swap(a, b);
				u -= t * v;
				std::swap(u, v);
			}
			return mod_int(u);
		}
	}

	mod_int pow(long long t) const {
		assert(!(x == 0 && t == 0));
		mod_int e = *this, res = mod_int(1);
		for (; t; e *= e, t >>= 1)
			if (t & 1) res *= e;
		return res;
	}

	mod_int fact() {
		if (_fact[0].x == 0) prepare();
		return _fact[x];
	}

	mod_int inv_fact() {
		if (_fact[0].x == 0) prepare();
		return _inv_fact[x];
	}

	mod_int choose(mod_int y) {
		assert(y.x <= x);
		return this->fact() * y.inv_fact() * mod_int(x - y.x).inv_fact();
	}

	static mod_int _inv[TABLE_SIZE + 1];

	static mod_int _fact[TABLE_SIZE + 1];

	static mod_int _inv_fact[TABLE_SIZE + 1];

	static void prepare() {
		_inv[1] = 1;
		for (int i = 2; i <= (int)TABLE_SIZE; ++i) {
			_inv[i] = 1LL * _inv[MODULO % i].x * (MODULO - MODULO / i) % MODULO;
		}
		_fact[0] = 1;
		for (unsigned i = 1; i <= TABLE_SIZE; ++i) {
			_fact[i] = _fact[i - 1] * int(i);
		}
		_inv_fact[TABLE_SIZE] = _fact[TABLE_SIZE].inv();
		for (int i = (int)TABLE_SIZE - 1; i >= 0; --i) {
			_inv_fact[i] = _inv_fact[i + 1] * (i + 1);
		}
	}
};

template <int M, unsigned F>
std::ostream &operator<<(std::ostream &os, const mod_int<M, F> &rhs) {
	return os << rhs.x;
}

template <int M, unsigned F>
std::istream &operator>>(std::istream &is, mod_int<M, F> &rhs) {
	long long s;
	is >> s;
	rhs = mod_int<M, F>(s);
	return is;
}

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv[TABLE_SIZE + 1];

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
bool operator==(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
	return lhs.x == rhs.x;
}

template <int M, unsigned F>
bool operator!=(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
	return !(lhs == rhs);
}

const int MF = 1000010;
const int MOD = 1000000007;

using mint = mod_int<MOD, MF>;

mint nCr(int n, int r) {
	mint ans = 1;
	for (int i = n, count = 0; count < r; i--, count++) {
		ans *= i;
	}
	for (int i = r; i > 0; i--) {
		ans /= i;
	}
	return ans;
}

int fact[1000010];

signed main() {
	int N, M, O;
	cin >> N >> M;
	mint ans = 1;
	for (int i = 2; i*i <= M; i++) {
		int count = 0;
		while (M%i == 0) {
			count++;
			M /= i;
		}
		if (count == 0) continue;
		ans *= nCr(count + N - 1, N - 1);

	}

	if (M != 1) {
		ans *= N;
	}

	cout << ans << "\n";

	return 0;
}