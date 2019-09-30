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
int64_t K;
int64_t A[100000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N >> K;
	for (int32_t i = 0; i < N; i++)
	{
		in >> A[i];
	}
	for (int32_t i = 0; i < N; i++)
	{
		if (A[i] == 0) { out << N << endl; return 0; }
	}

	int32_t res = 0;
	int64_t tmp = 1;
	int32_t l = 0;
	for (int32_t i = 0; i < N; i++)
	{
		//[l,i]

		tmp *= A[i];
		while (tmp > K && l<=i) {
			tmp /= A[l];
			++l;
		}
		res = std::max(res, i - l+1);
	}
	out << res << endl;

	return 0;
}
#endif