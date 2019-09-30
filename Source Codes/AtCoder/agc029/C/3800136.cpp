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
	usize n;
	::std::cin >> n;
	::std::vector<u32> a(n);
	for (auto &e : a) {
		::std::cin >> e;
	}
	const auto is_ok = [&](const usize sig)->bool {
		::std::vector<::std::pair<u32, usize>> pos({ {0,0} });
		u32 prev{ 0 };
		for (const auto e : a) {
			if (prev >= e) {
				while (pos.back().first > e) {
					pos.pop_back();
				}
				u32 p = e;
				while (true) {
					if (p == 0) return false;
					if (pos.back().first != p) {
						pos.emplace_back(p, 0);
					}
					if (pos.back().second == sig - 1) {
						pos.pop_back();
						--p;
						continue;
					}
					break;
				}
				++pos.back().second;
			}
			prev = e;
		}
		return true;
	};
	usize ng = 0, ok = n;
	while (ok - ng > 1) {
		const usize mid = (ng + ok) / 2;
		if (is_ok(mid))ok = mid;
		else ng = mid;
	}
	::std::cout << ok << ::std::endl;
	return 0;
}