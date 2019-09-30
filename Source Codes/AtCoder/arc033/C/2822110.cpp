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
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;


inline constexpr uint32_t get_min2pow(uint32_t value, uint32_t work = 1) {
	return ((value <= work) ? (work) : (get_min2pow(value, work * 2)));
}
template<typename T, size_t N_input>
class BIT
{
private:
	static constexpr size_t N = get_min2pow(N_input);
	// [1, n]
	T bit[N + 1];
public:
	//1-indexed [1,i]
	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	//1-indexed [i,j]
	T sum(int i, int j) {
		return sum(j) - sum(i - 1);
	}
	//1-indexed
	void add(int i, int x) {
		while (i <= N) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int32_t N;
BIT<int32_t, 200001> bit;
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	while (N--)
	{
		int t,x;
		in >> t>>x;
		if (t == 1)
		{
			bit.add(x, 1);
		}
		else
		{
			using BS_INT = int64_t;
			BS_INT ok_range = 0, ng_range = 200000 + 1;
			while (std::abs(ok_range - ng_range) > 1) {
				BS_INT mid = (ok_range + ng_range) / 2;
				bool is_ok = false;

				//?????
				is_ok = bit.sum(mid) < x;

				if (is_ok) {
					ok_range = mid;
				}
				else {
					ng_range = mid;
				}
			}
			bit.add(ok_range+1, -1);
			out << ok_range+1 << endl;
		}
	}

	return 0;
}
#endif