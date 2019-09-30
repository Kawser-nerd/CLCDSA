#include <cstdint>

template <::std::uint_least32_t Modulus> class modint {
	using u32 = ::std::uint_least32_t;
	using u64 = ::std::uint_least64_t;

public:
	using value_type = u32;
	value_type a;
	constexpr modint(const value_type x = 0) noexcept : a(x) {}
	constexpr value_type value() const noexcept { return a; }
	constexpr modint operator+(const modint &o) const noexcept {
		return a + o.a < Modulus ? modint(a + o.a) : modint(a + o.a - Modulus);
	}
	constexpr modint operator-(const modint &o) const noexcept {
		return modint(a < o.a ? a + Modulus - o.a : a - o.a);
	}
	constexpr modint operator*(const modint &o) const noexcept {
		return modint(static_cast<u64>(a) * o.a % Modulus);
	}
	constexpr modint operator/(const modint &o) const {
		return modint(static_cast<u64>(a) * (~o).a % Modulus);
	}
	modint &operator+=(const modint &o) noexcept {
		if ((a += o.a) >= Modulus)
			a -= Modulus;
		return *this;
	}
	modint &operator-=(const modint &o) noexcept {
		if (a < o.a)
			a += Modulus;
		a -= o.a;
		return *this;
	}
	modint &operator*=(const modint &o) noexcept {
		a = static_cast<u64>(a) * o.a % Modulus;
		return *this;
	}
	modint &operator/=(const modint &o) {
		a = static_cast<u64>(a) * (~o).a % Modulus;
		return *this;
	}
	modint operator~() const noexcept { return pow(Modulus - 2); }
	modint operator-() const noexcept { return a ? modint(Modulus - a) : *this; }
	modint &operator++() noexcept {
		if (++a == Modulus)
			a = static_cast<value_type>(0);
		return *this;
	}
	modint &operator--() noexcept {
		if (!a)
			a = Modulus;
		--a;
		return *this;
	}
	constexpr bool operator==(const modint &o) const noexcept { return a == o.a; }
	constexpr bool operator!=(const modint &o) const noexcept { return a != o.a; }
	constexpr bool operator<(const modint &o) const noexcept { return a < o.a; }
	constexpr bool operator<=(const modint &o) const noexcept { return a <= o.a; }
	constexpr bool operator>(const modint &o) const noexcept { return a > o.a; }
	constexpr bool operator>=(const modint &o) const noexcept { return a >= o.a; }
	constexpr explicit operator bool() const noexcept { return a; }
	constexpr explicit operator value_type() const noexcept { return a; }
	modint pow(u64 x) const noexcept {
		u64 t = a, u = 1;
		while (x) {
			if (x & 1)
				u = u * t % Modulus;
			t = (t * t) % Modulus;
			x >>= 1;
		}
		return modint(u);
	}
};

#include <iostream>
#include <string>
#include <vector>

int main(void) {
	using mint = modint<1000000007>;
	int n;
	std::string s;
	std::cin >> n >> s;
	mint dp[5003][5003] = {};
	dp[0][0] = 1;
	for (int i = 1;i <= n;++i) {
		dp[i][0] = dp[i - 1][1] * 2 + dp[i - 1][0];
		for (int j = 1;j <= i;++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] * 2;
		}
	}
	std::cout << dp[n][s.length()].a << std::endl;
	return 0;
}