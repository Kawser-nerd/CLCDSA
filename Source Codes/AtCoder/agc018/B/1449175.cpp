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

int32_t N,M;
int32_t A[300][300];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>M;
	for (int32_t i = 0; i < N; ++i)	for (int32_t j = 0; j < M; ++j)
	{
		in >> A[i][j];
	}
	int32_t max_n = 1;
	for (; max_n <= N; ++max_n)
	{
		int32_t num[300] = {};
		int32_t index[300] = {};
		for (int32_t i = 0; i < N; ++i) {
			num[A[i][index[i]]]++;
		}
		bool ok = false;
		while (!ok)
		{
			ok = true;
			for (int32_t i = 0; i < N; ++i) {
				auto m = A[i][index[i]];
				if (num[m] > max_n) {
					ok = false;
					++index[i];
					if (index[i] >= M) {
						goto fail;
					}
					num[A[i][index[i]]]++;
				}
			}
		}

		break;
	fail:;
	}
	out << max_n << endl;
	return 0;
}
#endif