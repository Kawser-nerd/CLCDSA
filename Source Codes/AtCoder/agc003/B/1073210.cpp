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
int32_t num[100000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> num[i];
	}
	int64_t count = 0;
	bool rem = false;
	for (int32_t i = 0; i < N; ++i)
	{
		if (rem)++num[i];
		count += num[i]/2;
		rem = (num[i] / 2) && (num[i] & 1);
	}

	out << count << endl;
	return 0;
}
#endif