#if 1
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <iomanip>
#include <assert.h>

#define in std::cin
#define out std::cout

int main()
{
	int32_t N, x;
	in >> N >> x;
	int32_t l, r;
	int64_t count = 0;
	in >> r;
	if (x < r) {
		count += (r - x);
		r = x;
	}
	for (int32_t i = 1; i < N; ++i)
	{
		l = r;
		in >> r;
		if (x < l + r) {
			auto eat = (l + r) - x;
			r -= eat;
			assert(0 <= r);
			count += eat;
		}
	}
	out << count << std::endl;
}
#endif