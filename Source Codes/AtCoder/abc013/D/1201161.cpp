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

auto& in = std::cin;
auto& out = std::cout;

int32_t N, M, D;
int32_t res[30][100000];//2^i???j????????
int32_t a[200000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in >> N >> M >> D;
	for (size_t i = 0; i < N; i++)
	{
		res[0][i] = i;
	}
	for (size_t i = 0; i < M; i++)
	{
		in >> a[i];
		std::swap(res[0][a[i] - 1], res[0][a[i]]);
	}
	for (size_t j = 1; j < 30; j++)
	{
		for (size_t i = 0; i < N; i++)
		{
			res[j][i] = res[j - 1][res[j - 1][i]];
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		int bace = i;
		auto d = D;
		int32_t tmp = 0;
		while (d) {
			if (d & 1) {
				bace = res[tmp][bace];
			}
			d >>= 1;
			++tmp;
		}
		a[bace] = i;
	}
	for (size_t i = 0; i < N; i++)
	{
		out << a[i] + 1 << endl;
	}

	return 0;
}
#endif