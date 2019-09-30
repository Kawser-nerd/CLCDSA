//#define NDEBUG
#include <cstddef>
#include <cstdint>
#include <vector>

using i8 = ::std::int_least8_t;
using i32 = ::std::int_least32_t;
using i64 = ::std::int_least64_t;
using u8 = ::std::uint_least8_t;
using u32 = ::std::uint_least32_t;
using u64 = ::std::uint_least64_t;
using isize = ::std::ptrdiff_t;
using usize = ::std::size_t;

template <class T = usize> class rep {
	const T f, l;

public:
	class itr {
		friend rep;
		T i;
		constexpr itr(T x) noexcept : i(x) {}

	public:
		void operator++() noexcept { ++i; }
		constexpr T operator*() const noexcept { return i; }
		constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr rep(const T first, const T last) noexcept : f(first), l(last) {}
	constexpr itr begin() const noexcept { return itr(f); }
	constexpr itr end() const noexcept { return itr(l); }
};
template <class T = usize> class revrep {
	const T f, l;

public:
	class itr {
		friend revrep;
		T i;
		constexpr itr(T x) noexcept : i(x) {}

	public:
		void operator++() noexcept { --i; }
		constexpr T operator*() const noexcept { return i; }
		constexpr bool operator!=(const itr x) const noexcept { return i != x.i; }
	};
	constexpr revrep(const T first, const T last) noexcept : f(first), l(last) {}
	constexpr itr begin() const noexcept { return itr(l - 1); }
	constexpr itr end() const noexcept { return itr(f - 1); }
};
template <class T> bool amax(T &a, const T &b) {
	return a <= b ? (a = b, 1) : 0;
}
template <class T> bool amin(T &a, const T &b) {
	return b <= a ? (a = b, 1) : 0;
}
template <class T> bool samax(T &a, const T &b) {
	return b <= a ? 0 : (a = b, 1);
}
template <class T> bool samin(T &a, const T &b) {
	return a <= b ? 0 : (a = b, 1);
}
template <class T> using vec_alias = ::std::vector<T>;
template <class T> auto md_vec(usize n, const T &value) {
	return ::std::vector<T>(n, value);
}
template <class... Args> auto md_vec(usize n, Args... args) {
	return ::std::vector<decltype(md_vec(args...))>(n, md_vec(args...));
}
template <class T> const T &as_const(const T &v) noexcept { return v; }
template <class T> constexpr T difference(const T &a, const T &b) {
	return a <= b ? b - a : a - b;
}

#include <algorithm>
#include <iostream>
#include <utility>
#include <tuple>

int main() {
	u32 h, w;
	::std::cin >> h >> w;
	usize n;
	::std::cin >> n;
	::std::vector<::std::pair<u32, u32>> p(n);
	for (auto &e : p) {
		::std::cin >> e.first >> e.second;
	}
	::std::sort(p.begin(), p.end());
	u32 cnt{ 0 };
	for (const auto &e : p) {
		u32 x, y;
		::std::tie(x, y) = e;
		if (x < y + cnt)
			continue;
		if (x == y + cnt) {
			++cnt;
			continue;
		}
		::std::cout << x - 1 << ::std::endl;
		return 0;
	}
	::std::cout << h << ::std::endl;
	return 0;
}