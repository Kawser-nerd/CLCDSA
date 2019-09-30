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
int64_t X;
int64_t x[200000];

int64_t func(int64_t stream)
{
	int64_t res = 0;
	int64_t k = 1;
	for (int32_t i = N-1; i >= 0; i-= stream)
	{
		++k;
		for (int32_t j = i; j > std::max<int32_t>(-1, i- stream); j--)
		{
			int64_t add = k * k - (k - 1)*(k - 1);
			if (k == 2) { add = 4; res += x[j]; }
			res += add* x[j];
		}
	}

	return res + stream * X + X * N;
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N >> X;

	for (int32_t i = 0; i < N; i++)
	{
		in >> x[i];
	}

	using BS_INT = int64_t;
	BS_INT ok_range = 1, ng_range = N + 1;
	while (std::abs(ok_range - ng_range) > 2) {
		BS_INT mid1 = ok_range - (ok_range - ng_range) / 3;
		BS_INT mid2 = ok_range - (ok_range - ng_range)*2 / 3;

		//?????

		int64_t score1 = func(mid1), score2= func(mid2);


		if (score1 < score2) {
			ng_range = mid2;
		}
		else {
			ok_range = mid1;
		}
	}
	int64_t score1 = func(ok_range), score2 = func(ok_range+1);

	out << std::min(score1, score2) << endl;

	return 0;
}
#endif