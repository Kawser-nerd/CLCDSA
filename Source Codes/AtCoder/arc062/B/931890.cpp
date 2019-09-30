#include <iomanip>
#include <utility>
#include <algorithm>
#include <type_traits>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#include <array>
#include <chrono>
#include <random>
#include <forward_list>
#include <iomanip>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;
#define MFOR(i,end) for(size_t i = 0, end_i = (end); i < end_i; ++ i)

struct my_int {
	int32_t v = -999999;
	my_int() {}
	my_int(int32_t u) :v(u) {}
	operator int32_t& () { return v; }
	operator const int32_t& ()const { return v; }
};
namespace std {
	template<>
	struct hash<my_int>
		: hash<int32_t>
	{};
}
//dp[i][j] = i+1????j???????????????
//std::unordered_map<int32_t, my_int> dp[100000];
my_int dp[1000][1000];

int N;
char s[100009];

////dp[i][j] = i+1????j???????????????
//constexpr int32_t f(int32_t i, int32_t j)
//{
//	if (i <= 0) {
//		return -1;
//	}
//	if (j <= 0) {
//		return f(i - 1, j) - 1;// +(s[i] == 'g' ? 1 : 0);
//	}
//	return std::max(f(i - 1, j - 1), f(i - 1, j) - 1);// +(s[i] == 'g' ? 1 : 0);
//}

int main()
{
	std::cin >> s;
	N = strlen(s);

	//for (size_t i = 0; i < N_MAX; i++) {
	//	dp[0][i] = -1;
	//}
	//for (size_t i = 1; i < N_MAX; i++) {
	//	dp[i][0] = dp[i - 1][0] - 1;
	//	for (size_t j = 1; j < N_MAX/2; ++j) {
	//		dp[i][j] = std::max(dp[i-1][j-1], dp[i - 1][j] - 1);
	//	}
	//}


	//std::cout << f(N - 1, N / 2) + std::count_if(s, s + N, [](char c) {return c == 'g'; }) << std::endl;
	std::cout << -(N-(N / 2)) + std::count_if(s, s + N, [](char c) {return c == 'g'; }) << std::endl;

	return 0;
}