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

char S[100000000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> S;
	int32_t count[4] = {};
	auto g = [](char c) {
		switch (c)
		{
		case 'N':return 0;
		case 'W':return 1;
		case 'S':return 2;
		case 'E':return 3;
		}
		return 0;
	};
	for (auto i = S;*i != '\0';++i)
	{
		++count[g(*i)];
	}

	if (
		(count[g('N')] > 0) == (count[g('S')] > 0) &&
		(count[g('W')] > 0) == (count[g('E')] > 0)
		) {
		out << "Yes";
	}
	else {

		out << "No";
	}
	out << endl;
	return 0;
}
#endif