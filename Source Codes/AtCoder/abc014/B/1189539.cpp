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

#define in std::cin
#define out std::cout

int32_t N,X;
int32_t a[1000];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N>>X;
	for (size_t i = 0; i < N; i++)
	{
		in >> a[i];
	}
	int res = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (X&(1 << i)) {
			res += a[i];
		}
	}
	out << res << endl;
	return 0;
}
#endif

#if 0
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

#define in std::cin
#define out std::cout


template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}


int32_t N,Q;
std::vector<int32_t> graph[100000];
int32_t parent[100000][30];//2^j????
int32_t dep[100000];
void dfs(int i, int p, int d)
{
	dep[i] = d;
	parent[i][0] = p;
	for (size_t j = 1; j< d; j++)
	{
		parent[i][j] = parent[parent[i][j - 1]][j - 1];
	}
	for (auto& c : graph[i]) {
		dfs(c, i, d+1);
	}
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	fill_all(parent, 0);
	in >> N>>Q;
	for (size_t i = 0; i < N-1; i++)
	{
		int a, b;
		in >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dep[0] = 0;
	for (auto& c : graph[0]) {
		dfs(c, 0,1);
	}


	for (size_t i = 0; i < Q; i++)
	{
		int a, b;
		in >> a >> b; --a; --b;
		int length = 1;
		if (dep[a] > dep[b]) {
			std::swap(a, b);
		}
		length += dep[b] - dep[a];
		int clib = dep[b] - dep[a];
		int tmp = 0;
		while (clib) {
			if (clib & 1) {
				b = parent[b][tmp];
			}
			clib >>= 1;
			++tmp;
		}

		int beg = 0, end = 25;
		while (beg + 1 != end)
		{

		}
	}

	return 0;
}
#endif