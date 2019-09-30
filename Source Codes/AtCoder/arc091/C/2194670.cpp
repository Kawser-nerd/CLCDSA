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

int32_t N, Inc,Dec;
int32_t res[600000];
auto iter = res;
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >>N>> Inc>>Dec;

	{
		//for (int32_t i = Inc-1; i >= 0 ; --i)
		//{
		//	*iter++ = N - i;
		//}
		//for (int32_t i = Dec - 2; i >= 0; --i)
		//{
		//	*iter++ = i+1;
		//}
		for (int32_t i = 1; i <= Inc; i++) {
			if (iter >= (res + N)) { out << -1 << endl; return 0; }
			*iter++ = N - Inc + i;
		}
		for (int32_t i = 1; i <= Dec - 1; i++) {
			if (iter >= (res + N)) { out << -1 << endl; return 0; }
			*iter++ = Dec - i;
		}

		//int32_t rem = N - (iter - res);
		//if (rem<0 || rem > (Dec - 1)*(Inc - 1)) {
		//	out << -1 << endl; return 0;
		//}

		int32_t count = 1;
		int32_t start = Dec - 1;
		while (iter < (res + N))
		{
			start += Dec - 1;
			start = std::min(start, N - Inc + 1 - 1);
			for (int32_t i = 0; i < Dec - 1 && iter < (res + N); i++) {
				*iter++ = start - i;
			}
			++count;
			if (count > Inc) {
				//assert(false);
				out << -1 << endl; return 0;
			}
		}
		/*
		int32_t bottom = Dec;
		while (iter < (res + N)) {
			auto iter_last = iter;
			iter += (Dec - 1);
			iter = std::min(res + N, iter);
			auto iter_next = iter;
			for (int32_t i = 0; i < Dec-1 && iter_last<iter; i++)
			{
				*--iter = i + bottom;
			}
			iter = iter_next;
			//for (int32_t i = Dec - 1 - 1; iter != (res + N) && i >= 0; --i)
			//{
			//	*iter++ = i + bottom;
			//}
			bottom += Dec - 1;
			if (bottom >= N - (Inc - 1)) { break; }
		}
		*/
		out << res[0];
		for (int32_t i = 1; i < N; i++)
		{
			out << ' ' << res[i];
		}
		out << endl;
	}

	return 0;
}
#endif