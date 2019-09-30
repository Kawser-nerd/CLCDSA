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
#include <bitset>
#include <assert.h>

auto& in = std::cin;
auto& out = std::cout;

int32_t N;
std::pair<int64_t, int64_t> value[200000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> value[i].first >> value[i].second;
		if (value[i].first > value[i].second) { std::swap(value[i].first, value[i].second); }
	}
	std::sort(value, value + N);

	int64_t min_value;
	int64_t max_diff;
	//????????
	{
		int64_t A_MAX = -1, A_MIN = 100000000000000000;
		int64_t I_MAX = -1, I_MIN = 100000000000000000;
		for (int32_t i = 0; i < N; ++i)
		{
			A_MAX = std::max(A_MAX, value[i].second); A_MIN = std::min(A_MIN, value[i].second);
			I_MAX = std::max(I_MAX, value[i].first ); I_MIN = std::min(I_MIN, value[i].first );
		}
		min_value = (A_MAX - A_MIN)*(I_MAX - I_MIN);
		max_diff = A_MAX - I_MIN;
	}
	//????????
	int64_t diff2_sec_min = value[0].second;
	int64_t diff2_max = value[N-1].first;
	for (int32_t i = 1; i < N; ++i)
	{
		//???????=>????????????=>??
		//????????????=>?????????????
		//???????value[i].first???
		diff2_sec_min = std::min(diff2_sec_min, value[i - 1].second);
		diff2_max = std::max(diff2_max, value[i - 1].second);
		min_value = std::min(min_value, max_diff*(diff2_max- std::min(diff2_sec_min,value[i].first)));
	}
	std::cout << min_value << std::endl;


	return 0;
}
#endif