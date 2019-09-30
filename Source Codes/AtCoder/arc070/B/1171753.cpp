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

int32_t N, K;
int32_t a[5000];

template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}

constexpr int32_t INF = 2'000'000'000;
constexpr int32_t NUMBER = 5000;
int32_t ignore = -1;
int32_t sum[NUMBER + 1];
int8_t dp[NUMBER][NUMBER + 1];
//[i]???value?????????????????true
int8_t func(int i, int value)
{
	if (value <= 0) {
		return value==0?1:0;
	}
	//if (i == N) {
	if (sum[i] < value) {
		return 0;
	}
	if (dp[i][value] != -1) {
		return dp[i][value];
	}

	auto pata = func(i + 1, value);
	if (i == ignore) {
		return dp[i][value] = std::move(pata);
	}
	return dp[i][value] = (pata | func(i + 1, value - a[i]));
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N >> K;
	for (size_t i = 0; i < N; i++)
	{
		in >> a[i];
		if (a[i] >= K) { --N; --i; }
	}
	std::sort(a, a + N);
	for (int i = N - 1; i >= 0; i--)
	{
		sum[i] = a[i] + sum[i + 1];
	}
	if (sum[0]<K) {
		out << N<<endl;
		return 0;
	}
	using BS_INT = int64_t;
	BS_INT beg = -1, end = N + 1;
	while (beg + 1 != end) {
		BS_INT mid = (beg + end) / 2;
		bool ok = false;
		//?????
		for (auto& arr : dp)for (auto& i : arr) { if (i==0) { i = -1; } }
		ignore = mid;
		for (int v = K - a[mid]; v < K; ++v) {
			ok = func(0, v);
			if (ok) {
				break;
			}
		}
		if (ok) {
			end = mid;//??
		}
		else {
			beg = mid;//??
		}
	}
	out << beg+1 << endl;

	return 0;
}
#endif