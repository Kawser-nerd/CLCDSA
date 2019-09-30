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

	for (int32_t i = 0; i < W; i++) { out << '.'; }out << endl;
	for (int32_t i = 1; i < H - 1; i++) {
		out << '.';
		for (int32_t j = 1; j < W - 1; j++) {
			if (i & 1) { out << '#'; }
			else { out << ((j != W - 2) ? map[i][j] : '#'); }
		}
		out << '.'; out << endl;
	}
	for (int32_t i = 0; i < W; i++) { out << '.'; }out << endl;

	out<< endl;

	for (int32_t i = 0; i < W; i++) { out << '#'; }out << endl;
	for (int32_t i = 1; i < H - 1; i++) {
		out << '#';
		for (int32_t j = 1; j < W-1; j++) {
			if (i & 1) { out << map[i][j]; }
			else { out << ((j != W - 2) ? '#' : map[i][j]); }
		}
		out << '#'; out << endl;
	}
	for (int32_t i = 0; i < W; i++) { out << '#'; }out << endl;

	return 0;
}
#endif