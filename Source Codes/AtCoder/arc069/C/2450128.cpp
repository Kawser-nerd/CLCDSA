//#define NDEBUG
#define _CRT_SECURE_NO_WARNINGS
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <memory>
#include <string>
#include <type_traits>

template <class Integral> class Rirange;

template <class Integral = std::size_t> class irange {
public:
	using value_type = Integral;
	using reference = value_type &;
	using const_reference = const value_type &;
	class irangeitr {
		friend irange;
		value_type i;
		irangeitr(const value_type x) noexcept : i(x) {}

	public:
		void operator++() noexcept { ++i; }
		value_type &operator*() noexcept { return i; }
		const_reference operator*() const noexcept { return i; }
		bool operator!=(const irangeitr &x) const noexcept { return i < x.i; }
	};

private:
	const value_type f, l;

public:
	irange(const value_type first, const value_type last) noexcept
		: f(first), l(last) {}
	irangeitr begin() const noexcept { return irangeitr(f); }
	irangeitr end() const noexcept { return irangeitr(l); }
	Rirange<value_type> rev() const noexcept {
		return Rirange<value_type>(l - 1, f - 1);
	}
};
template <class Integral = std::size_t> class Rirange {
public:
	using value_type = Integral;
	using reference = value_type &;
	using const_reference = const value_type &;
	class Rirangeitr {
		friend Rirange;
		value_type i;
		Rirangeitr(const value_type x) noexcept : i(x) {}

	public:
		void operator++() noexcept { --i; }
		reference operator*() noexcept { return i; }
		const_reference operator*() const noexcept { return i; }
		bool operator!=(const Rirangeitr &x) const noexcept {
			return (!~x.i && ~i) || x.i < i;
		}
	};

private:
	const value_type f, l;

public:
	Rirange(const value_type x, const value_type y) noexcept : f(x), l(y) {}
	Rirangeitr begin() const noexcept { return Rirangeitr(f); }
	Rirangeitr end() const noexcept { return Rirangeitr(l); }
	irange<value_type> rev() const noexcept {
		return irange<value_type>(l + 1, f + 1);
	}
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
	const std::array<int, 10> itoc;
	std::array<std::uint_least8_t, 256> ctoi_base;
	const std::uint_least8_t *const ctoi;
	void get_c() { c = fgetc(stdin); }
	void put_c(int x) { fputc(x, stdout); }
	bool vacant() { return c == ' ' || c == '\n'; }
	operator int() { return 0; }

	explicit customIO()
		: itoc({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }),
		ctoi(std::addressof(ctoi_base[-static_cast<std::int_fast16_t>(
			std::numeric_limits<char>::min())])) {
		for (std::uint_least8_t i = 0; i < 10; ++i)
			ctoi_base[static_cast<int>("0123456789"[i]) -
			static_cast<std::int_fast16_t>(
				std::numeric_limits<char>::min())] = i;
	}
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
			d = d * 10 + ctoi[c];
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
			d = d * 10 + ctoi[c];
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
			buf[c++] = itoc[d % 10], d /= 10;
		if (!c)
			buf[c++] = itoc[0];
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
			buf[c++] = itoc[d % 10], d /= 10;
		if (!c)
			buf[c++] = itoc[0];
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

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <functional>
#include <iterator>
#include <utility>
#include <vector>

template <class T>
using ComparessDefaultContainer = std::vector<T, std::allocator<T>>;

template <class T = std::int_fast64_t,
	template <class> class Container = ComparessDefaultContainer,
	class Compare = std::less<typename Container<T>::value_type>>
	class Compress {
	public:
		using container_type = Container<T>;
		using value_compare = Compare;
		using value_type = typename container_type::value_type;
		using reference = typename container_type::reference;
		using const_reference = typename container_type::const_reference;
		using size_type = typename container_type::size_type;

	protected:
		container_type c;
		value_compare comp;

	public:
		Compress() : c(), comp() {}
		explicit Compress(const value_compare &x) : comp(x) {}
		explicit Compress(const value_compare &x, const container_type &other)
			: c(other), comp(x) {
			build();
		}
		explicit Compress(const value_compare &x, container_type &&other)
			: c(std::move(other)), comp(x) {
			build();
		}

		size_type size() const { return c.size(); }
		bool empty() const { return c.empty(); }

		size_type zip(const value_type &x) const {
			const auto t = std::upper_bound(c.begin(), c.end(), x, comp);
			assert(t != c.begin());
			return static_cast<size_type>(std::distance(c.begin(), t) - 1);
		}
		size_type operator()(const value_type &x) const { return zip(x); }
		const_reference unzip(const size_type x) const {
			assert(x < size());
			return c[x];
		}
		const_reference operator[](const size_type x) const { return unzip(x); }

		void push(const value_type &x) { c.push_back(x); }
		void push(value_type &&x) { c.push_back(std::move(x)); }
		template <class... Args> void emplace(Args &&... args) {
			c.emplace_back(std::forward<Args>(args)...);
		}
		void build() {
			std::sort(c.begin(), c.end(), comp);
			c.erase(std::unique(c.begin(), c.end()), c.end());
		}
};
#include<vector>
#include<string>
#include<array>
#include<utility>
int main() {
	const auto n = IO.input<uint32>();
	std::vector<uint32> a(n);
	for (auto &e : a)
		IO >> e;
	Compress<std::pair<uint32, uint32>> c;
	{
		uint32 cur = 0;
		for (const auto i : irange<>(0, n))
			if (smaxi(cur, a[i]))
				c.emplace(a[i], i);
	}
	c.emplace(0, 0);
	c.build();
	std::vector<uint64> imos(c.size(), 0);
	std::vector<uint64> ans(n, 0);
	for (const auto e : a) {
		const auto t = c(std::make_pair(e, n));
		if (t != c.size() - 1)
			ans[c[t + 1].second] += e - c[t].first;
		if (t)
			imos[t - 1]++;
	}
	for (const auto i : irange<>(1, c.size()).rev())
		imos[i - 1] += imos[i];

	for (const auto i : irange<>(1, c.size())) {
		ans[c[i].second] += imos[i - 1] * (c[i].first - c[i - 1].first);
	}
	for (const auto e : ans)
		IO << e << '\n';
	return 0;
}