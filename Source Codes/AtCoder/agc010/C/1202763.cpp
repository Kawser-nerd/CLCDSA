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
std::vector<int32_t> graph[100000];//?
int32_t need[100000] = {};
bool ans = true;
//@return ??i???????
int32_t dfs(int i, int p)
{
	if (graph[i].size() == 1) {
		return need[i];
	}

	int32_t child_total = 0;
	for (auto& c : graph[i]) {
		if (c != p) {
			auto add = dfs(c, i);
			if (add > need[i]) {
				ans = false;
				return 0;
			}
			child_total += add;
		}
	}

	int32_t up = need[i]*2 - child_total;
	if (up < 0 || need[i] < up) {
		ans = false;
		return 0;
	}
	return up;
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	in >> N;
	for (int32_t i = 0; i < N; ++i)
	{
		in >> need[i];
	}
	for (int32_t i = 0; i < N-1; ++i)
	{
		int a, b;
		in >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	if (N == 2) {
		ans = (need[0] == need[1]);
	}
	else {
		for (int32_t i = 0; i < N; ++i)
		{
			if (graph[i].size() != 1) {
				if (dfs(i, i) != 0) {
					ans = false;
				}
				break;
			}
		}
	}
	out << ((ans) ? ("YES") : ("NO")) << endl;
	return 0;
}
#endif