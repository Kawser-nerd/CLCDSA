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

std::string S;
int DP[100000];

bool begin_of(int i, const char* str) {
	auto iter = S.begin() + i; auto iter_end = S.end();
	while (iter != iter_end && *str != '\0') {
		if (*iter != *str) {
			return false;
		}
		++iter; ++str;
	}
	return  (*str == '\0');
}
template<size_t N>
constexpr size_t str_len_c(const char(&)[N]) { return N - 1; }
bool func(int i)
{
	if (S.size() <= i) { return true; }
	if (DP[i] != -1) { return DP[i] != 0; }
#define DO_FUNC_11(STR) \
	if (begin_of(i, #STR)) {\
		if(func(i + str_len_c(#STR))){\
			DP[i] = 1; return true;\
		}\
	}
	DO_FUNC_11(dream);
	DO_FUNC_11(dreamer);
	DO_FUNC_11(erase);
	DO_FUNC_11(eraser);
	DP[i] = 0; return false;
#undef DO_FUNC_11
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> S;
	for (auto& i : DP)
	{
		i = -1;
	}
	out << (func(0) ? "YES" : "NO");
	return 0;
}
#endif