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
std::set<int64_t> sA;
int64_t num[100000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> num[i];
		sA.insert((num[i]<<32)|i);
	}
	{
		auto iter = sA.begin();
		for (int32_t i = 0; i < N; ++i)
		{
			num[(*iter)& 0xffffffff] = i;
			++iter;
		}
	}

	int64_t count = 0;
	for (int32_t i = 0; i < N; ++i)
	{
		count += std::abs(i - num[i]) & 1;
	}
	out << (count >> 1) + (count & 1) << endl;

	return 0;
}
#endif