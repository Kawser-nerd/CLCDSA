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

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;

	if (N < 100) {
		out << "00" << endl;
	}
	else  if (N <= 5000) {
		auto s = std::to_string((N / 100));
		if (s.size() == 1) {
			s = '0' + s;
		}
		out << s << endl;
	}
	else if (N <= 30000) {
		out << (N / 1000) + 50 << endl;
	}
	else if (N <= 70000) {
		N /= 1000;
		N -= 30;
		N /= 5;
		N += 80;
		out << N << endl;
	}
	else {
		out << 89 << endl;
	}

	return 0;
}
#endif