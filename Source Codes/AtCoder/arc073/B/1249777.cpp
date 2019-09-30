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

int32_t N;
int64_t W[100];
int64_t V[100];
std::unordered_map<int64_t, int64_t> dp[100];
int64_t func(int i, int64_t W_MAX)
{
	if (W_MAX < 0) {
		return -100000000000000;
	}
	if (i >= N) {
		return 0;
	}
	if (dp[i].count(W_MAX)) {
		return dp[i][W_MAX];
	}
	auto& memo = dp[i][W_MAX];
	return memo = std::max(
		func(i + 1, W_MAX),
		func(i + 1, W_MAX - W[i]) + V[i]
	);
}
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	int64_t W_MAX;
	in >> N>>W_MAX;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> W[i] >> V[i];
	}
	std::cout << func(0, W_MAX) << std::endl;

	return 0;
}
#endif