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

int32_t N, K;
int64_t a[100001];
int64_t sum[100001];
int64_t score[100001];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);
	

	in >> N >> K;
	for (size_t i = 1; i <= N; i++)
	{
		in >> a[i];
		sum[i] = sum[i - 1] + a[i];
		score[i] = score[i - 1] + std::max<int64_t>(0, a[i]);
	}

	int64_t res = sum[N];
	for (size_t i = 1; i+K - 1 <= N; i++)
	{
		res = std::max(res, score[N] - (score[i + K-1] - score[i - 1]) + std::max<int64_t>(0, sum[i + K - 1] - sum[i - 1]));
	}

	out << res << endl;

	return 0;
}
#endif