#if 2
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


#define in std::cin
#define out std::cout



int main()
{
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	auto c = [](bool b) {return b ? 1 : 0; };
	std::string S;
	in >> S;
	if (c((S.size() % 2) == 0) == c(S.front() == S.back())) {
		out << "First";
	}
	else {
		out << "Second";
	}
	out << std::endl;
	return 0;
}
#endif