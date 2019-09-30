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

//dp[i] = i+1?????????????
uint64_t dp[1000];
int N;
int T[1000];
int A[1000];

//uint64_t f(int i)
//{
//	if (i <= 0) {
//		return T[0] + A[0];
//	}
//	uint64_t last_bace = f(i - 1) / (T[i - 1] + A[i - 1]);
//	uint64_t last_T = last_bace * T[i - 1];
//	uint64_t last_A = last_bace * A[i - 1];
//
//	uint64_t new_T = (1 < T[i]) ? (last_T + (T[i] - last_T % T[i])) : (last_T);
//	uint64_t new_A = (new_T / T[i])*A[i];
//	if (last_A <= new_A) {
//	}
//	else {
//		new_A = (1 < A[i]) ? (last_A + (A[i] - last_A % A[i])) : (last_A);
//		new_T = (new_A / A[i])*T[i];
//	}
//	return new_T + new_A;
//}

int main()
{
	std::cin >> N;
	for (size_t i = 0; i < N; ++i)
	{
		std::cin >> T[i] >> A[i];
	}

	dp[0] = T[0] + A[0];
	for (size_t i = 1; i < N; ++i)
	{
		uint64_t last_bace = dp[i - 1] / (T[i - 1] + A[i - 1]);
		uint64_t last_T = last_bace * T[i - 1];
		uint64_t last_A = last_bace * A[i - 1];

		uint64_t new_T = (0 < last_T % T[i]) ? (last_T + (T[i] - last_T % T[i])) : (last_T);
		uint64_t new_A = (new_T / T[i])*A[i];
		if (last_A <= new_A) {
		}
		else {
			new_A = (0 < last_A % A[i]) ? (last_A + (A[i] - last_A % A[i])) : (last_A);
			new_T = (new_A / A[i])*T[i];
		}
		dp[i] = new_T + new_A;
	}

	std::cout << dp[(N - 1)] << std::endl;

	return 0;
}