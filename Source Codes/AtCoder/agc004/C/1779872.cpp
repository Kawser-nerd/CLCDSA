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

int32_t H,W;
std::string map[510];
std::string map2[510];
std::string map3[510];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> H>>W;
	for (int32_t i = 0; i < H; i++)
	{
		in >> map[i];
	}
	for (int32_t i = 0; i < H; i++) {
		map2[i] = map[i];
		map3[i] = map[i];
	}

	for (int32_t i = 1; i < H-1; ++i) {
		if (i & 1)
		{
			for (auto& c : map2[i]) { c = '#'; }
			map2[i].front() = map2[i].back() = '.';
		}
		else
		{
			map2[i][W - 2] = '#';
		}
	}
	for (int32_t i = 0; i < H; ++i) {
		map3[i].front() = map3[i].back() = '#';
		if (i & 1)
		{
		}
		else
		{
			for (auto& c : map3[i]) { c = '#'; }
			if(map[i][W-2]=='.'){ map3[i][W - 2] = '.';	}
		}
	}
	for (auto& i : map3[0]) { i = '#'; }
	for (auto& i : map3[H-1]) { i = '#'; }

	for (int32_t i = 0; i < H; i++) {
		out << map2[i] << endl;
	}
	out<< endl;
	for (int32_t i = 0; i < H; i++) {
		out << map3[i] << endl;
	}

	return 0;
}
#endif