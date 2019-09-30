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

int32_t N;
int32_t A[110001];
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
		int a;
		in >> a; A[a]++;
	}

	int32_t max = 0;
	for (int32_t  i = 1; i < 100010; i++)
	{
		max = std::max(max, A[i - 1] + A[i] + A[i + 1]);
	}
	out << max << endl;

	return 0;
}
#endif