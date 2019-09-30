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
#define all(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N,K;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>K;

	int64_t res = 0;
	for (int32_t b = K+1; b <= N; b++)
	{
		int32_t addnum = (N / b);
		res += addnum * (b - K);
		if (K == 0) { res -= 1; }
		auto tmp = N % b;
		res += std::max(0, tmp+1 - K);
	}
	
	out << res << endl;
	return 0;
}
#endif