//#define NDEBUG
#define _CRT_SECURE_NO_WARNINGS
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>
#include <vector>

template <class Integral = std::size_t> class irange {
public:
	using value_type = Integral;
	using const_value = const value_type;
	class irangeitr {
		friend irange;
		value_type i;
		irangeitr(const_value x) noexcept : i(x) {}

	public:
		void operator++() noexcept { ++i; }
		const_value operator*() const noexcept { return i; }
		bool operator!=(const irangeitr &x) const noexcept { return i != x.i; }
	};
	class revrange {
		friend irange;
		const_value f, l;
		revrange(const_value x, const_value y) noexcept : f(x), l(y) {}

	public:
		class revitr {
			friend revrange;
			value_type i;
			revitr(const_value x) noexcept : i(x) {}

		public:
			void operator++() noexcept { --i; }
			const_value operator*() const noexcept { return i - 1; }
			bool operator!=(const revitr &x) const noexcept { return i != x.i; }
		};
		revitr begin() const noexcept { return revitr(f); }
		revitr end() const noexcept { return revitr(l); }
	};

private:
	const_value f, l;

public:
	irange(const_value first, const_value last) noexcept : f(first), l(last) {}
	irangeitr begin() const noexcept { return irangeitr(f); }
	irangeitr end() const noexcept { return irangeitr(l); }
	revrange rev() const noexcept { return revrange(l, f); }
};

template <class T> bool maxi(T &a, const T &b) {
	if (b < a)
		return 0;
	a = b;
	return 1;
}
template <class T> bool mini(T &a, const T &b) {
	if (a < b)
		return 0;
	a = b;
	return 1;
}
template <class T> bool smaxi(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T> bool smini(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}
struct customIO {
	int c;
	bool f;
	std::array<int, 30> buf;
	void get_c() { c = fgetc(stdin); }
	void put_c(int x) { fputc(x, stdout); }
	bool vacant() { return c == ' ' || c == '\n'; }
	operator int() { return 0; }

	// in

	void cueing() {
		while (get_c(), vacant())
			;
	}
	template <class T>
	auto operator>>(T &d) ->
		typename std::enable_if<std::is_signed<T>::value, customIO &>::type {
		d = 0;
		f = 0;
		cueing();
		if (c == '-')
			f = 1, get_c();
		do
			d = d * 10 + c - '0';
		while (get_c(), !vacant());
		if (f)
			d = -d;
		return *this;
	}
	template <class T>
	auto operator>>(T &d) ->
		typename std::enable_if<!std::is_signed<T>::value, customIO &>::type {
		d = 0;
		cueing();
		do
			d = d * 10 + c - '0';
		while (get_c(), !vacant());
		return *this;
	}
	customIO &operator>>(char &d) {
		cueing();
		d = c;
		return *this;
	}
	customIO &operator>>(double &d) {
		scanf("%lf", &d);
		return *this;
	}
	customIO &operator>>(std::string &d) {
		d.clear();
		cueing();
		do
			d.push_back(c);
		while (get_c(), !vacant());
		return *this;
	}
	template <class T> T input() {
		T d;
		*this >> d;
		return d;
	}

	// out

	template <class T>
	auto operator<<(T d) ->
		typename std::enable_if<std::is_signed<T>::value, customIO &>::type {
		c = 0;
		f = 0;
		if (d < static_cast<T>(0))
			f = 1, d = -d;
		while (d)
			buf[c++] = d % 10 + '0', d /= 10;
		if (!c)
			buf[c++] = '0';
		if (f)
			put_c('-');
		while (c--)
			put_c(buf[c]);
		return *this;
	}
	template <class T>
	auto operator<<(T d) ->
		typename std::enable_if<!std::is_signed<T>::value, customIO &>::type {
		c = 0;
		while (d)
			buf[c++] = d % 10 + '0', d /= 10;
		if (!c)
			buf[c++] = '0';
		while (c--)
			put_c(buf[c]);
		return *this;
	}
	customIO &operator<<(char d) {
		put_c(d);
		return *this;
	}
	customIO &operator<<(double d) {
		printf("%f", d);
		return *this;
	}
	customIO &operator<<(const std::string &d) {
		for (const auto e : d)
			put_c(e);
		return *this;
	}
	customIO &operator<<(const char *d) {
		while (*d != '\0')
			put_c(*(d++));
		return *this;
	}
	void endl() { put_c('\n'); }
	void space() { put_c(' '); }
} IO;

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;
#include<functional>

int main() {
	uint32 n;
	IO >> n;
	std::vector<std::string> s(n), t(n, std::string(n, 0));
	for (auto &e : s)IO >> e;
	auto ch = [&](uint32 a,uint32 b) {
		for (const auto i : irange<>(0, n))
			for (const auto j : irange<>(0, n))
				t[i][j] = s[(i + a) % n][(j + b) % n];
		for (const auto i : irange<>(0, n))
			for (const auto j : irange<>(0, n))
				if (t[i][j] != t[j][i]) return false;
		return true;
	};
	uint32 ans = 0;
	for (const auto i : irange<>(0, n)) {
		if (ch(0, i))ans += n - i;
	}
	for (const auto i : irange<>(1, n)) {
		if (ch(i, 0))ans += n - i;
	}
	IO << ans << '\n';
	return 0;
}