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
int32_t x;
int64_t a[2000];
int64_t dp[2000][2000];/*
int64_t func(int32_t i, int32_t n)
{
	int64_t res = 0;
	for (int32_t ln = 1; ln < n-1; ++ln)
	{
		auto tmp = func(i, ln);
		res += tmp + x
	}
}*/
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	for (int32_t i = 0; i < 3; ++i)
	{
		in >> a[i];
	}
	if (std::any_of(a, a + 3, [](int v) {return !(v & 1); })) {
		out << 0 << std::endl; return 0;
	}
	std::sort(a, a + 3);
	out << a[0]*a[1]<< std::endl;

	/*
	in >> N>>x;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> a[i];
	}*/


	return 0;
}
#endif