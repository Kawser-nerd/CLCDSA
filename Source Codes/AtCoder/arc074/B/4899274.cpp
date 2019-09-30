#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <utility>
#include <vector>


template <class Key, class T, class Compare = std::less<Key>,
	class Operate = std::plus<T>, class Invert = std::negate<T>>
	class priority_sum {
	public:
		using key_type = Key;
		using mapped_type = T;
		using key_compare = Compare;
		using mapped_operate = Operate;
		using mapped_invert = Invert;
		using value_type = std::pair<key_type, mapped_type>;
		using container_type = std::vector<value_type, std::allocator<value_type>>;
		using size_type = typename container_type::size_type;

	private:
		class value_compare {
			const key_compare &comp;

		public:
			value_compare(const key_compare &comp) : comp(comp) {}
			bool operator()(const value_type &l, const value_type &r) const {
				return comp(l.first, r.first);
			}
		};
		class value_compare_rev {
			const key_compare &comp;

		public:
			value_compare_rev(const key_compare &comp) : comp(comp) {}
			bool operator()(const value_type &l, const value_type &r) const {
				return comp(r.first, l.first);
			}
		};

		mapped_type sum;
		key_compare comp;
		mapped_operate oper;
		mapped_invert inve;
		container_type left, right;

	public:
		priority_sum(mapped_type identity, key_compare comp = key_compare(),
			mapped_operate oper = mapped_operate(),
			mapped_invert inve = mapped_invert())
			: sum(identity), comp(comp), oper(oper), inve(inve), left(), right() {}

		bool empty() const noexcept { return left.empty() && right.empty(); }
		size_type size() const noexcept { return left.size() + right.size(); }
		const mapped_type &get_sum() const noexcept { return sum; }

		void expand() {
			assert(("called priority_sum::expand on rightmost bound", !right.empty()));
			sum = oper(sum, right.front().second);
			std::pop_heap(right.begin(), right.end(), value_compare(comp));
			left.emplace_back(std::move(right.back()));
			right.pop_back();
			std::push_heap(left.begin(), left.end(), value_compare_rev(comp));
		}
		void shrink() {
			assert(("called priority_sum::shrink on leftmost bound", !left.empty()));
			sum = oper(sum, inve(left.front().second));
			std::pop_heap(left.begin(), left.end(), value_compare_rev(comp));
			right.emplace_back(std::move(left.back()));
			left.pop_back();
			std::push_heap(right.begin(), right.end(), value_compare(comp));
		}
		template <class... Args> void emplace(Args &&... args) {
			left.emplace_back(std::forward<Args>(args)...);
			sum = oper(sum, left.back().second);
			std::push_heap(left.begin(), left.end(), value_compare_rev(comp));
			shrink();
		}
};

#include <algorithm>
#include <iostream>
#include <vector>

void ARC074_D() {
	using ll = long long;

	int n;
	std::cin >> n;
	std::vector<ll> a(3 * n);
	for (int i = 0; i < 3 * n; i++)
		std::cin >> a[i];

	priority_sum<ll, ll,std::less<ll>> ps1(0);
	std::vector<ll> dp1(3 * n);
	for (int i = 0; i < 3 * n; i++) {
		if (i == n)
			for (int j = 0;j < n;++j)
				ps1.expand();
		if (i >= n)
			dp1[i] = ps1.get_sum();
		ps1.emplace(a[i],a[i]);
	}

	priority_sum<ll, ll,std::greater<ll>> ps2(0);
	std::vector<ll> dp2(3 * n);
	for (int i = 3 * n - 1; i >= 0; i--) {
		ps2.emplace(a[i],a[i]);
		if (i == 2 * n)
			for (int j = 0;j < n;++j)
				ps2.expand();
		if (i <= 2 * n)
			dp2[i] = ps2.get_sum();
	}

	ll ans = dp1[n] - dp2[n];
	for (int i = n; i <= 2 * n; i++)
		ans = std::max(ans, dp1[i] - dp2[i]);

	std::cout << ans << std::endl;
	return;
}

int main() {
	ARC074_D();
	return 0;
} ./Main.cpp:59:12: warning: expression result unused [-Wunused-value]
                        assert(("called priority_sum::expand on rightmost bound", !right.empty()));
                                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/assert.h:89:5: note: expanded from macro 'assert'
  ((expr)                                                               \
    ^~~~
./Main.cpp:100:9: note: in instantiation of member function 'priority_sum<long long, long long, std::__1::less<long long>, std::__1::plus<long long>, std::__1::negate<long long> >::expand' requested here
                                ps1.expand();
                                    ^
./Main.cpp:67:12: warning: expression result unused [-Wunused-value]
                        assert(("called priority_sum::shrink on leftmost bound", !left.empty()));
                                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/assert.h:89:5: note: expanded from macro 'assert'
  ((expr)                     ...