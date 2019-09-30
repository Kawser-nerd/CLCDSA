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

auto& in = std::cin;
auto& out = std::cout;

uint64_t a,b_raw,b_big, b_rem;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> a>>b_raw;
	if (a == b_raw) {
		std::cout << 1 << std::endl;
		return 0;
	}

	for (;;)
	{
		for (size_t i = 0; i <= 61; i++) {
			if (b_raw & ((uint64_t)(1) << i)) {
				b_big = ((uint64_t)(1) << i);
			}
		}
		b_rem = b_raw - b_big;

		if (a & b_big) {
			b_raw -= b_big;
			a -= b_big;
			continue;
		}

		//if (b_big <= a) {
		//	std::cout << (b_raw - a + 1) << std::endl;
		//	return 0;
		//}

		break;
	}

	//rem????
	if(b_rem!=0){
		uint64_t rem=0;
		for (size_t i = 0; i <= 61; i++) {
			if (b_rem & ((uint64_t)(1) << i)) {
				rem = ((uint64_t)(1) << i);
			}
		}
		rem *= 2;
		b_rem = rem - 1;
	}

	uint64_t count=0;
	count += (b_big - a);
	count += b_big;
	count -= a;
	count += std::min(a,b_rem + 1);
	std::cout << count << std::endl;

	return 0;
}
#endif