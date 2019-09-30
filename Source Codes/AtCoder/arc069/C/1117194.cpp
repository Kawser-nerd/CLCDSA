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
std::pair<int32_t, int32_t> a[100000+1];
int64_t count[100001] = {};

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> a[i].first; a[i].second = i;
	}
	a[N].first = 0; a[N].second = 0; ++N;
	std::sort(a, a + N, std::greater<>{});

	int32_t beg_index = a[0].second;
	int32_t max_v = a[0].first;
	for (int32_t i = 1; i < N; ++i)
	{
		if (a[i].first < max_v) {
			count[beg_index] += i * int64_t(max_v - a[i].first);
			max_v = a[i].first;
		}
		beg_index = std::min(beg_index, a[i].second);
	}
	for (int32_t i = 0; i < N-1; ++i)
	{
		out << count[i] << '\n';
	}

	return 0;
}
#endif