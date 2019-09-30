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

constexpr int64_t INF = 1000000000100000;
int32_t N;
int64_t A[2000];
int64_t x;
int64_t dp[2001][2001];

template<typename T>
void fill_all(T& a,const T& b)
{
	a = b;
}
template<typename T, size_t N, typename U>
void fill_all(T(& a)[N], const U& b)
{
	for (auto& i : a) {
		fill_all(i, b);
	}
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N >> x;
	for (int i = 0; i < N; ++i)
	{
		in >> A[i];
	}
	fill_all(dp, INF);
	int64_t min = INF;
	{
		int64_t tmp = 0;
		for (int i = 0; i < N; ++i)
		{
			dp[0][i] = A[i];
			tmp += dp[0][i];
		}
		min = std::min(min, tmp);
	}
	for (int c = 1; c <= N; ++c)
	{
		int64_t tmp = x*c;
		for (int i = 0; i < N; ++i)
		{
			int next = (i-c+N) % N;
			dp[c][i] = std::min(dp[c-1][i], A[next]);
			tmp += dp[c][i];
		}
		min = std::min(min, tmp);
	}

	std::cout << min << endl;

	return 0;
}
#endif