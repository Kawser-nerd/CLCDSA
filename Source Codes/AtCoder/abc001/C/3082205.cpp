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

int32_t D, P;

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> D >> P; D *= 10; P *= 10;
	if (P < 25 * 6) {
		out << 'C' << ' ';
	}
	else if (D < 1125) {
		out << "N" << ' ';
	}
	else if (D < 3375) {
		out << "NNE" << ' ';
	}
	else if (D < 5625) {
		out << "NE" << ' ';
	}
	else if (D < 7875) {
		out << "ENE" << ' ';
	}
	else if (D < 10125) {
		out << "E" << ' ';
	}
	else if (D < 12375) {
		out << "ESE" << ' ';
	}
	else if (D < 14625) {
		out << "SE" << ' ';
	}
	else if (D < 16875) {
		out << "SSE" << ' ';
	}
	else if (D < 19125) {
		out << "S" << ' ';
	}
	else if (D < 21375) {
		out << "SSW" << ' ';
	}
	else if (D < 23625) {
		out << "SW" << ' ';
	}
	else if (D < 25875) {
		out << "WSW" << ' ';
	}
	else if (D < 28125) {
		out << "W" << ' ';
	}
	else if (D < 30375) {
		out << "WNW" << ' ';
	}
	else if (D < 32625) {
		out << "NW" << ' ';
	}
	else if (D < 34875) {
		out << "NNW" << ' ';
	}
	else {
		out << "N" << ' ';
	}

	__COUNTER__;
	if (P < 25 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 155 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 335 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 545 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 795 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 1075 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 1385 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 1715 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 2075 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 2445 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 2845 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else if (P < 3265 * 6) {
		out << __COUNTER__ - 1 << endl;
	}
	else {
		out << __COUNTER__ - 1 << endl;
	}


	return 0;
}
#endif