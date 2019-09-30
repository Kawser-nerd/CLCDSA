#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>

auto& in = std::cin;
auto& out = std::cout;

int32_t X, K, Q;
int32_t R[100001];
inline constexpr uint32_t get_min2pow(uint32_t value, uint32_t work = 1) {
	return ((value <= work) ? (work) : (get_min2pow(value, work * 2)));
}

struct value_type
{
	int32_t diff = 0;
	int32_t max = 1000010000;
	int32_t min = -1000010000;
};
template<uint32_t N_RAW_MAX>
class segment_tree
{
public:
	static constexpr uint32_t N_MAX = get_min2pow(N_RAW_MAX);
private:
	value_type default_value;
	value_type value[N_MAX * 2 - 1] = {};
	static inline constexpr int32_t getchild(int i) {
		return i * 2 + 1;
	}
	static inline constexpr int32_t getparent(int i) {
		return (i - 1) / 2;
	}
	void Init_impl(int k = 0)
	{
		if (k < N_MAX - 1) {
			//???
			auto c1 = getchild(k), c2 = c1 + 1;
			Init_impl(c1);
			Init_impl(c2);
			value[k] = merge(value[c1], value[c2]);
		}
		else {
			//?
			value[k] = default_value;
		}
	}
	value_type query_impl(int32_t a, int32_t b, int32_t k = 0, int32_t l = 0, int32_t r = N_MAX)const
	{
		if (r <= a || b <= l)return default_value;
		if (a <= l && r <= b)return value[k];
		int m = (l + r) / 2;
		return merge(query_impl(a, b, getchild(k), l, m), query_impl(a, b, getchild(k) + 1, m, r));
	}

public:
	template<typename T, typename FUNC>
	void change(int32_t i, T&& v, FUNC&& operation = std::plus<>{})
	{
		i += N_MAX - 1;
		//?
		value[i] = std::forward<FUNC>(operation)(std::move(value[i]), std::forward<T>(v));
		i = getparent(i);
		//???
		for (;;) {
			auto c1 = getchild(i), c2 = c1 + 1;
			value[i] = merge(value[c1], value[c2]);
			if (i == 0) { break; }
			i = getparent(i);
		}
	}

	//-----------------------------???????????-----------------------------//
private:
	static inline value_type merge(const value_type& l, const value_type& r)
	{
		value_type res;
		res.diff = l.diff + r.diff;
		res.max = std::max(std::min(l.max, r.max - l.diff), r.min - l.diff);
		res.min = std::min(std::max(l.min, r.min - l.diff), r.max - l.diff);


		assert(res.max >= res.min);
		return res;
	}
public:
	inline void init()
	{
		//default_value = ;
		Init_impl();
	}
	inline value_type query(int32_t a, int32_t b)const
	{
		return query_impl(a, b);
	}
};
segment_tree<100000> segtree;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> X;
	in >> K;
	for (size_t i = 1; i <= K; i++)
	{
		in >> R[i];
	}
	for (size_t i = 1; i <= K; i++)
	{
		int32_t diff = R[i] - R[i - 1];
		diff = std::min(X, diff);
		if ((i & 1) == 1)
		{
			//A??=>A??
			value_type tmp;
			tmp.max = X;
			tmp.min = diff;
			tmp.diff = -diff;
			segtree.change(i, tmp, [](const value_type&, const value_type&newv) {return newv; });
		}
		else
		{
			//A??
			value_type tmp;
			tmp.max = X - diff;
			tmp.min = 0;
			tmp.diff = +diff;
			segtree.change(i, tmp, [](const value_type&, const value_type&newv) {return newv; });
		}
	}
	in >> Q;
	while (Q--)
	{
		int a, t;
		in >> t >> a;

		auto iter = std::upper_bound(R, R + K + 1, t);
		auto vvv = segtree.query(0, iter - R);//??????
		a = std::max(a, vvv.min);
		a = std::min(a, vvv.max);
		a += vvv.diff;
		t = t - *(iter - 1);

		if (((iter - R) & 1) == 1)
		{
			//A??=>A??
			a -= t;
			a = std::max(0, a);
		}
		else
		{
			//A??
			a += t;
			a = std::min(a, X);
		}
		out << a << endl;
	}

	return 0;
}
#endif