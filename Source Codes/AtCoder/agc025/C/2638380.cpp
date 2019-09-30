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
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N;
int32_t L[100010];
int32_t R[100010];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;

	for (size_t i = 0; i < N; i++)
	{
		in >> L[i]>>R[i];
	}

	std::sort(L, L + N, std::greater<>{});
	std::sort(R, R + N);
	L[N] = -10000000;
	R[N] = -10000000;

	int64_t max = 0;
	int64_t res = 0;
	int64_t count = 0;
	for (int32_t i = 0; i < N; i++)
	{
		res += 2 * L[i];
		while (true) {
			if (i + 2 <= count) { break; }
			if (count < i || 0 > R[count]) {
				res += -2 * R[count];
				++count;
			}
			else { break; }
		}
		max = std::max(res, max);
	}
	res = 0;
	count = 0;
	for (int32_t i = 0; i < N; i++)
	{
		res += -2 * R[i];
		while (true) {
			if (i + 2 <= count) { break; }
			if (count < i || 0 <= L[count]) {
				res += 2 * L[count];
				++count;
			}
			else { break; }
		}
		max = std::max(res, max);
	}
	out << max << endl;

	return 0;
}
#endif