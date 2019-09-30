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
std::string S;
int32_t Enum[300100];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>S;
	for (size_t i = 1; i <= N; i++)
	{
		if (S[i - 1] == 'E') { ++Enum[i]; }
		Enum[i] += Enum[i - 1];
	}

	int32_t min = N;
	for (int i = N; i >= 1; i--)
	{
		min = std::min(min, ((i-1) - Enum[i - 1]) + (Enum[N] - Enum[i]));
	}
	out << min << endl;
	return 0;
}
#endif