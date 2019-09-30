#include <cstdint>
#include <type_traits>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>

template<typename RET = uint64_t, typename Integral>
RET combination(Integral all, Integral get)
{
	assert(all >= get);
	get = std::min(all - get, get);
#if 1
	constexpr int32_t ALL_MAX = 10'000;
	static std::vector<RET> DP_comb[ALL_MAX+1];
	if (!DP_comb[all].empty())
	{
		return DP_comb[all][get];
	}

	if (DP_comb[0].empty())
	{
		DP_comb[0].resize(1);
		DP_comb[0][0] = (RET)1;
		DP_comb[1].resize(1);
		DP_comb[1][0] = (RET)1;
	}
	for (int32_t i = 2; i <= all; i++)
	{
		if (DP_comb[i].empty())
		{
			int32_t size = i/2 + 1;
			DP_comb[i].resize(size);
			DP_comb[i][0] = (RET)1;
			for (int32_t j = 1; j < size-1; j++)
			{
				DP_comb[i][j] = DP_comb[i - 1][j - 1] + DP_comb[i - 1][j];
			}
			DP_comb[i][size-1] = DP_comb[i - 1][size - 2] + DP_comb[i - 1][(i&1)?(size-1):(size - 2)];
		}
	}
	return DP_comb[all][get];
#else
	RET ret = (RET)1;
	for (Integral i = 1; i <= get; ++i)
	{
		ret *= all+1-i;
		ret /= i;
	}
	return ret;
#endif
}
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


#define in std::cin
#define out std::cout

int32_t N;
int32_t MIN, MAX;
int64_t A[100];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	in >> MIN >> MAX;
	for (size_t i = 0; i < N; i++)
	{
		in >> A[i];
	}
	std::sort(A, A + N, std::greater<>{});

	uint64_t sum = 0;
	for (size_t i = 0; i < MIN; ++i)
	{
		sum += A[i];
	}
	out << std::fixed << std::setprecision(10) << (double)(sum) / MIN << endl;

	auto range = std::equal_range(A, A + N, A[MIN - 1], std::greater<>{});
	auto range_lrngth = range.second - range.first;
	if (range_lrngth == 1)
	{
		out << 1 << endl; return 0;
	}
	auto not_free = range.first - A;
	uint64_t count = 0;
	if (not_free == 0)
	{
		for (int i = MIN; i <= std::min<int>(MAX, range_lrngth); ++i)
		{
			auto free = (MIN - not_free) + (i - MIN);
			//count += fact_v[range_lrngth] / fact_v[free] / fact_v[range_lrngth - free];
			count += combination(range_lrngth, free);
		}
	}
	else
	{
		auto free = (MIN - not_free) + (MIN - MIN);
		//count += fact_v[range_lrngth] / fact_v[free] / fact_v[range_lrngth - free];
		count += combination(range_lrngth, free);
	}
	out << count << endl;

	return 0;
}
#endif