#include <algorithm>
#include <cassert>
#include <cstdint>
#include <functional>
#include <utility>
#include <vector>

template <typename T = std::int_fast64_t, class Container = std::vector<T>,
	class Compare = std::less<typename Container::value_type>>
	class Compress {
	public:
		using container_type = Container;
		using value_compare = Compare;
		using value_type = typename container_type::value_type;
		using reference = typename container_type::reference;
		using const_reference = typename container_type::const_reference;
		using size_type = typename container_type::size_type;

	protected:
		container_type c;
		value_compare comp;

	public:
		explicit Compress(const value_compare &x = value_compare()) : comp(x) {}
		explicit Compress(const container_type &x,
			const value_compare &y = value_compare())
			: c(x), comp(y) {
			build();
		}
		explicit Compress(container_type &&x,
			const value_compare &y = value_compare())
			: c(std::move(x)), comp(y) {
			build();
		}
		bool empty() const { return c.empty(); }
		size_type size() const { return c.size(); }
		void push(const value_type &x) { c.push_back(x); }
		void push(value_type &&x) { c.push_back(std::move(x)); }
		template <class... Args> void emplace(Args &&... args) {
			c.emplace_back(std::forward<Args>(args)...);
		}
		void build() {
			std::sort(c.begin(), c.end(), comp);
			c.erase(std::unique(c.begin(), c.end()), c.end());
		}
		size_type zip(const value_type &x) const {
			return std::lower_bound(c.begin(), c.end(), x, comp) - c.begin();
		}
		const_reference unzip(const size_type x) const {
			assert(x < size());
			return c[x];
		}
};

#include<cstdint>
#include<cstdio>
#include<vector>

int main() {
	using uint = std::uint_fast32_t;
	uint n;
	scanf("%d", &n);
	std::vector<uint> a(n);
	for (auto &e : a)scanf("%d", &e);
	Compress<uint> c(a);
	for (const auto e : a)printf("%u\n", c.zip(e));
	return 0;
} ./Main.cpp:62:14: warning: format specifies type 'int *' but the argument has type 'uint *' (aka 'unsigned long *') [-Wformat]
        scanf("%d", &n);
               ~~   ^~
               %ld
./Main.cpp:64:31: warning: format specifies type 'int *' but the argument has type 'unsigned long *' [-Wformat]
        for (auto &e : a)scanf("%d", &e);
                                ~~   ^~
                                %ld
./Main.cpp:66:39: warning: format specifies type 'unsigned int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
        for (const auto e : a)printf("%u\n", c.zip(e));
                                      ~~     ^~~~~~~~
                                      %lu
3 warnings generated.