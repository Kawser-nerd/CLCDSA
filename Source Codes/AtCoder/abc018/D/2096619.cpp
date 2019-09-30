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

int32_t N,M;
int32_t P, Q;
int32_t R;
int32_t x[1818];
int32_t y[1818];
int32_t z[1818];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>M>>P>>Q>>R;
	for (int32_t i = 0; i < R; i++)
	{
		in >> x[i] >> y[i] >> z[i]; --x[i]; --y[i];
	}
	int32_t res = 0;
	for (uint32_t LOOP = 0; LOOP < (1u << N); LOOP++)
	{
		std::bitset<32> bit{LOOP};
		if (bit.count() != P) { continue; }
		int32_t score[18] = {};
		for (int32_t i = 0; i < R; i++)
		{
			if (bit[x[i]]) {
				score[y[i]] += z[i];
			}
		}
		std::sort(score,score+M, std::greater<>{});
		res = std::max(res, std::accumulate(score, score + Q, 0));
	}

	out << res << endl;

	return 0;
}
#endif