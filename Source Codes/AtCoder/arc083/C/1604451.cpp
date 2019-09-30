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

auto& in = std::cin;
auto& out = std::cout;

int32_t N;
int32_t X[1000];
int32_t Y[1000];
int32_t P[1000];//?
std::vector<int32_t> C[1000];//?
void input_tree()
{
	in >> N;
	for (int32_t i = 1; i <= N - 1; ++i)
	{
		int p;
		in >> p; ; --p;
		P[i] = p;
		C[p].push_back(i);
	}
}

template<typename T, typename U>
std::enable_if_t<std::rank<T>::value == 0> fill_all(T& arr, const U& v) {
	arr = v;
}
template<typename ARR, typename U>
std::enable_if_t<std::rank<ARR>::value != 0> fill_all(ARR& arr, const U& v) {
	for (auto& i : arr) {
		fill_all(i, v);
	}
}
int32_t dp[1000][5001];//???????????
int32_t DP(int i, int w, int V)
{
	if (i >= C[V].size()) {
		return (w>=0)?0:50001000;
	}
	if (w < 0) {
		return 50001000;
	}
	if (dp[i][w] != -1) {
		return dp[i][w];
	}
	return dp[i][w] = std::min(DP(i + 1, w - X[C[V][i]], V)+Y[C[V][i]], DP(i + 1, w - Y[C[V][i]], V)+ X[C[V][i]]);
}

bool func(int i)
{
	if (C[i].empty()) {
		return true;
	}
	for (auto& c : C[i])
	{
		if (!func(c)) { return false; }
	}
	for (int32_t j = 0; j < C[i].size(); j++)
	{
		fill_all(dp[j], -1);
	}
	Y[i] = DP(0, X[i], i);
	return Y[i]< 50001000;
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	input_tree();
	for (int32_t i = 0; i < N; i++)
	{
		in >> X[i];
	}
	if (N == 1) {
		out << "POSSIBLE" << endl; return 0;
	}

	out << (func(0) ? "POSSIBLE" : "IMPOSSIBLE") << endl;


	return 0;
}
#endif