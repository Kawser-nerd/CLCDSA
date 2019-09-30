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

template<typename T, typename U>
void fill_all_impl(T& arr, const U& v,...) {
	arr = v;
}
template<typename ARR, typename U>
auto fill_all_impl(ARR& arr, const U& v,std::nullptr_t = nullptr)->decltype(std::begin(arr),void()) {
	for (auto& i : arr) {
		fill_all_impl(i, v);
	}
}
template<typename T, typename U>
void fill_all(T& arr, const U& v) { fill_all_impl(arr, v,nullptr); }


int32_t N;
std::bitset<16> graph[32];//??
int64_t dp[1 << 16];
int64_t duuu[1 << 16][16];
//top??????????????
int64_t func(std::bitset<16> top)
{
	if (top.count() == N) {
		return 1;
	}
	auto& memo = dp[top.to_ulong()];
	if (memo !=-1) {
		return memo;
	}
	memo = 0;
	for (int32_t i = 0; i < N; ++i)
	{
		if (!top[i]) {
			if ((top&graph[i]) == 0) {
				memo += func(top | std::bitset<16>(1 << i));
			}
		}
	}
	return memo;
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);
	int M;
	fill_all(dp, -1);
	in >> N>>M;
	for (int32_t i = 0; i < M; ++i)
	{
		int a, b;
		in >> a >> b; --a; --b;
		graph[a][b] = 1;
	}
	out << func(0)<<endl;

	return 0;
}
#endif