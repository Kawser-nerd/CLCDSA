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

int32_t N;
constexpr int32_t MAX_N = 300000;//???
std::vector<int32_t> graph[MAX_N];
int parent[MAX_N][30] = {}; // ????(???????-1???)
int depth[MAX_N]; // ??????
void init_parent(int32_t v=0, int32_t p=0, int32_t d=0) {
	parent[v][0] = p;
	for (int32_t i = 0; parent[parent[v][i]][i] != 0; ++i) {
		parent[v][i + 1] = parent[parent[v][i]][i];
	}
	depth[v] = d;
	for (auto& c : graph[v]) {
		if (c != p) init_parent(c, v, d + 1);
	}
}
int32_t gLCA(int32_t v1, int32_t v2)
{
	if (depth[v1] > depth[v2]) {
		std::swap(v1, v2);
	}
	//???????
	{
		int32_t dis = depth[v2] - depth[v1];
		int32_t tmp = 0;
		while (dis) {
			if (dis & 1) {
				v2 = parent[v2][tmp];
			}
			dis >>= 1;
			++tmp;
		}
	}
	//LCA
	if (v1 == v2) {
		return v1;
	}
	for (int32_t k = 30 - 1; k >= 0; --k) {
		if (parent[v1][k] != parent[v2][k]) {
			v1 = parent[v1][k];
			v2 = parent[v2][k];
		}
	}
	return parent[v1][0];
}
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	for (int32_t i = 0; i < N-1; ++i)
	{
		int a, b;
		in >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	init_parent();
	int32_t Q;
	in >> Q;
	for (int32_t i = 0; i < Q; ++i)
	{
		int a, b;
		in >> a >> b; --a; --b;
		auto lca= gLCA(a, b);
		out << depth[a] + depth[b] - depth[lca] * 2 + 1 << endl;;
	}

	return 0;
}
#endif