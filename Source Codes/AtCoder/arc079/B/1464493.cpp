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

int64_t K;
constexpr int32_t N = 50;
int64_t A[N];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> K;
	for (int32_t i = 0; i < N; ++i)
	{
		A[i] = (K / N) + (N - 1) + 1;
	}
	for (int32_t num = N - (K%N);num>=1; --num)
	{
		for (int32_t i = 0; i < N; ++i)
		{
			if (i == (num - 1)) {
				A[i] -= N;
			}
			else {
				++A[i];
			}
		}
	}

	out << N<<endl;
	out << A[0];
	for (int32_t i = 1; i < N; ++i)
	{
		out<<' '<<A[i];
	}
	out << endl;
	return 0;
}
#endif