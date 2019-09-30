#ifndef ___CLASS_MATRIX
#define ___CLASS_MATRIX

#include <vector>
#include <cassert>
#include <cstddef>

template<class type>
class matrix {
private:
	std::size_t H, W;
	std::vector<type> mat;
public:
	matrix() : H(0), W(0), mat(std::vector<type>()) {};
	matrix(std::size_t N_) : H(N_), W(N_), mat(std::vector<type>(N_ * N_)) {};
	matrix(std::size_t H_, std::size_t W_) : H(H_), W(W_), mat(std::vector<type>(H_ * W_)) {};
	std::size_t get_h() const { return H; }
	std::size_t get_w() const { return W; }
	type& entry(std::size_t r, std::size_t c) { return mat[r * W + c]; }
	type entry(std::size_t r, std::size_t c) const { return mat[r * W + c]; }
	matrix& operator+=(const matrix& m) {
		assert(H == m.H && W == m.W);
		for (size_t i = 0; i < H; ++i) {
			for (size_t j = 0; j < W; ++j) {
				mat[i * W + j] += m.mat[i * W + j];
			}
		}
	}
	matrix& operator-=(const matrix& m) {
		assert(H == m.H && W == m.W);
		for (size_t i = 0; i < H; ++i) {
			for (size_t j = 0; j < W; ++j) {
				mat[i * W + j] -= m.mat[i * W + j];
			}
		}
	}
	matrix& operator*=(const matrix& m) {
		assert(W == m.H);
		matrix ans(H, m.W);
		for (size_t i = 0; i < H; ++i) {
			for (size_t j = 0; j < m.W; ++j) {
				for (size_t k = 0; k < W; ++k) {
					ans.mat[i * m.W + j] += mat[i * W + k] * m.mat[k * m.W + j];
				}
			}
		}
		return (*this) = ans;
	}
	matrix operator+(const matrix& m) const { return matrix(*this) += m; }
	matrix operator-(const matrix& m) const { return matrix(*this) -= m; }
	matrix operator*(const matrix& m) const { return matrix(*this) *= m; }
};

template<class type>
matrix<type> unit(std::size_t N) {
	matrix<type> ret(N);
	for (size_t i = 0; i < N; ++i) {
		ret.entry(i, i) = type(1);
	}
	return ret;
}

template<class type>
matrix<type> binpow(const matrix<type> &m, std::uint64_t b) {
	matrix<type> ans = unit<type>(m.get_h()), mul(m);
	while (b) {
		if (b & 1) ans *= mul;
		mul *= mul;
		b >>= 1;
	}
	return ans;
}

#endif // ___CLASS_MATRIX

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
	modint operator-() const { return modint(0) -= n; }
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

#include <iostream>
using namespace std;
using modulo = modint<1000000007>;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, X, LX = 0;
	cin >> N >> M;
	matrix<modulo> d(3, 1);
	d.entry(0, 0) = modulo(0);
	d.entry(1, 0) = modulo(1);
	d.entry(2, 0) = modulo(3);
	matrix<modulo> conv(3, 3);
	conv.entry(0, 0) = modulo(4); conv.entry(0, 1) = -modulo(2); conv.entry(0, 2) = modulo(1);
	conv.entry(1, 0) = modulo(1); conv.entry(1, 1) = modulo(0); conv.entry(1, 2) = modulo(0);
	conv.entry(2, 0) = modulo(0); conv.entry(2, 1) = modulo(1); conv.entry(2, 2) = modulo(0);
	for (int i = 0; i < M; ++i) {
		cin >> X;
		matrix<modulo> mul = binpow(conv, X - LX);
		d = mul * d;
		d.entry(1, 0) -= d.entry(0, 0);
		d.entry(2, 0) -= d.entry(0, 0) * 3;
		LX = X;
	}
	matrix<modulo> fmul = binpow(conv, N - LX);
	d = fmul * d;
	cout << d.entry(0, 0).get() << '\n';
	return 0;
}