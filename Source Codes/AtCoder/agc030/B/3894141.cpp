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
template <class T> bool asmax(T &a, const T &b) {
	return b <= a ? 0 : (a = b, 1);
}
template <class T> bool asmin(T &a, const T &b) {
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

int main() {
	u64 w;
	usize n;
	::std::cin >> w >> n;
	::std::vector<u64> x(n), lsum(n + 1), rsum(n + 1);
	for (const auto i : rep<>(0, n)) {
		::std::cin >> x[i];
		lsum[i + 1] = lsum[i] + x[i];
		rsum[i + 1] = rsum[i] + (w - x[i]);
	}
	const auto cl = [&lsum](const usize f, const usize l) {
		return lsum[l] - lsum[f];
	};
	const auto cr = [&rsum](const usize f, const usize l) {
		return rsum[l] - rsum[f];
	};
	u64 ans = 0;
	for (const auto i : rep<>(0, n)) {
		const usize l = i;
		const usize r = n - i;
		usize d;
		if (l != 0 && r != 0) {
			d = ::std::min(l, r);
			asmax(ans, cl(i - d, i) * 2 + cr(i, i + d) * 2 - (w - x[i]));
			asmax(ans, cl(i - d, i) * 2 + cr(i, i + d) * 2 - x[i - 1]);
		}
		if (r != 0) {
			d = ::std::min(l, r - 1);
			asmax(ans, cl(i - d, i) * 2 + cr(i, i + d + 1) * 2 - (w - x[i]));
		}
		if (l != 0) {
			d = ::std::min(l - 1, r);
			asmax(ans, cl(i - d - 1, i) * 2 + cr(i, i + d) * 2 - x[i - 1]);
		}
	}
	::std::cout << ans << ::std::endl;
	return 0;
}