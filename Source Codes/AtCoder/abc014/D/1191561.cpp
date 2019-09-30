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


template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}


int32_t N, Q;
std::vector<int32_t> graph[100000];
int32_t parent[100000][30];//2^j????
int32_t dep[100000];
bool vis[100000];
void dfs(int i, int p, int d)
{
	if (vis[i]) { return; }
	vis[i] = true;
	dep[i] = d;
	parent[i][0] = p;
	for (int32_t j = 0, v = i;; ++j) {
		if (parent[parent[v][j]][j] != 0) {
			parent[v][j + 1] = parent[parent[v][j]][j];
		}
		else {
			break;
		}
	}
	for (auto& c : graph[i]) {
		dfs(c, i, d + 1);
	}
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	fill_all(parent, 0);
	in >> N;
	for (size_t i = 0; i < N - 1; i++)
	{
		int a, b;
		in >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vis[0] = true;
	dep[0] = 0;
	for (auto& c : graph[0]) {
		dfs(c, 0, 1);
	}


	in >> Q;
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
		int bace_dep = dep[a];
		if (a != b) {
			// ?????LCA????
			for (int k = 25 - 1; k >= 0; k--) {
				if (parent[a][k] != parent[b][k]) {
					a = parent[a][k];
					b = parent[b][k];
				}
			}
			length += (bace_dep - dep[parent[a][0]]) * 2;
		}
		out << length << endl;
	}

	return 0;
}
#endif