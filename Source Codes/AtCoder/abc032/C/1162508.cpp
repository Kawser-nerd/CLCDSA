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

#define in std::cin
#define out std::cout

int32_t N;
int64_t S[100000];
int64_t K;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N>>K;
	for (size_t i = 0; i < N; ++i)
	{
		in >> S[i];
	}
	if (K <= 0) {
		out << ((std::any_of(S, S + N, [](auto v) {return v == 0; })) ? (N) : (0)) << endl;
		return 0;
	}

	int64_t count = 0;
	int64_t tmp=1;
	auto beg_iter = S;
	for (auto i = S;i != S+N;++i)
	{
		if (*i == 0) {
			count = N;
			break;
		}

		tmp *= *i;
		while (tmp > K) {
			tmp /= *beg_iter++;
		}
		count = std::max<int64_t>(count, i - beg_iter + 1);
	}
	out << count << endl;

	return 0;
}
#endif