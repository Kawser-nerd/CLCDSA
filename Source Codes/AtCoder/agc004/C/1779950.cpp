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
	map2[0].assign(W, '#'); map2[1].assign(W, '.');
	map3[0].assign(W, '.'); map3[1].assign(W, '#');
	for (int32_t i = 2; i < H; i++) {
		map2[i] = map2[i - 2];
		map3[i] = map3[i - 2];
	}
	for (int32_t i = 0; i < H; i++) {
		map2[i][0] = map3[i][W - 1] = '#';
		map2[i][W - 1] = map3[i][0] = '.';
	}

	for (int32_t i = 0; i < H; i++)
	{
		in >> map[i];
		for (int32_t j = 0; j < W; j++) {
			if (map[i][j] == '#') {
				map2[i][j] = map3[i][j] = '#';
			}
		}
	}

	for (int32_t i = 0; i < H; i++) {
		out << map2[i] << endl;
	}
	out << endl;
	for (int32_t i = 0; i < H; i++) {
		out << map3[i] << endl;
	}

	return 0;
}
#endif