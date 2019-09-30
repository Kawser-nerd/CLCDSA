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
#define all(C) std::begin(C), std::end(C)

int32_t H,W,h,w;
int64_t map[500][500];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> H>>W>>h>>w;
	for (int32_t i = 0; i < H; i+=h)
		for (int32_t j = 0; j < W; j += w)
	{
		map[i][j] = 1000000000 - 1;
	}
	for (int32_t i = h-1; i < H; i+=h)
		for (int32_t j = w-1; j < W; j += w)
	{
		map[i][j] = -1000000000;
	}

	int64_t sum = 0;
	for (int32_t i = 0; i < H; ++i)
		for (int32_t j = 0; j < W; ++j)
	{
		sum += map[i][j];
	}
	if (sum > 0) {
		out << "Yes\n";
		for (int32_t i = 0; i < H; ++i)
		{
			for (int32_t j = 0; j < W; ++j)
			{
				out << map[i][j] << ' ';
			}
			out << '\n';
		}
	}
	else {
		out << "No\n";
	}
	return 0;
}
#endif