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

auto& in = std::cin;
auto& out = std::cout;
template<typename ARR>
inline void add_full(ARR& v1, ARR& v2)
{
	v1 += v2;
}
template<typename ARR, size_t N>
inline void add_full(ARR(&v1)[N], ARR(&v2)[N])
{
	auto iter1 = v1, iter2 = v2, iter1end = v1 + N;
	while (iter1 != iter1end) {
		add_full(*iter1++, *iter2++);
	}
}
//1-indexed???
template<size_t N>void CuSum(int64_t (&arr)[N])
{
	for (size_t i = 2; i < N; i++)
	{
		arr[i] += arr[i-1];
	}
}
template<typename ARR, size_t N>void CuSum(ARR(&arr)[N])
{
	for (auto& arr2 : arr) {
		CuSum(arr2);
	}
	for (size_t i = 2; i < N; i++)
	{
		add_full(arr[i], arr[i - 1]);
	}
}
template<size_t N, size_t M>void CuSum(int64_t(&arr)[N][M])
{
	for (auto& arr2 : arr) {
		CuSum(arr2);
	}

	for (size_t i = 2; i < N; i++)
	{
		add_full(arr[i], arr[i - 1]);
	}
}
template<size_t N, size_t M, size_t O>void CuSum(int64_t(&arr)[N][M][O])
{
	for (auto& arr2 : arr) {
		CuSum(arr2);
	}

	for (size_t i = 2; i < N; i++)
	{
		add_full(arr[i], arr[i - 1]);
	}
}

int32_t N, M, Q;
int64_t map[2001][2010];
int64_t edgex[2010][2001];
int64_t edgey[2010][2001];


int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N>>M>>Q;

	for (size_t i = 1; i <= N; i++)
	{
		char buf[3000];
		in >> buf;
		for (size_t j = 1; j <= M; j++)
		{
			map[i][j] = buf[j-1]-'0';
		}
	}

/*
	for (size_t i = 1; i <= N; i++)
		for (size_t j = 2; j <= M; j++)
		{
			edge[i][j] += edge[i][j - 1] + (map[i][j-1] - '0' +map[i][j - 1] - '0')/2;
		}
	for (size_t i = 2; i <= N; i++)
		for (size_t j = 1; j <= M; j++)
	{
		edge[i][j] += edge[i - 1][j] + (map[i - 1][j] - '0' + map[i - 1][j] - '0') / 2;
	}
*/

	for (size_t i = 1; i <= N; i++)
		for (size_t j = 1; j <= M; j++)
		{
			edgex[i][j] += (map[i][j] + map[i][j - 1]) / 2;
			edgey[i][j] += (map[i][j] + map[i - 1][j]) / 2;
		}
	CuSum(map);
	CuSum(edgex);
	CuSum(edgey);


	for (size_t i = 0; i < Q; i++)
	{
		int x, y, x2, y2;
		in >> x >> y >> x2 >> y2;
		--x; --y;
		std::swap(x, y); std::swap(x2, y2);

		auto v = (map[y2][x2] - map[y][x2] - map[y2][x] + map[y][x]);
		auto e = (edgex[y2][x2] - edgex[y][x2] - edgex[y2][x+1] + edgex[y][x+1])+ (edgey[y2][x2] - edgey[y+1][x2] - edgey[y2][x] + edgey[y+1][x]);
		std::cout << v-e<<endl;
	}



	return 0;
}
#endif