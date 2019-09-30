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
 
int64_t N;
std::unordered_set<int64_t> graph[100000];//?
int64_t need[100000] = {};
int64_t use[100000] = {};
bool is_lef[100000] = {};
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
 
	in >> N;
	for (int64_t i = 0; i < N; ++i)
	{
		in >> need[i];
	}
	for (int64_t i = 0; i < N-1; ++i)
	{
		int a, b;
		in >> a >> b; --a; --b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
 
	std::queue<int64_t> que;
	for (int64_t i = 0; i < N; ++i)
	{
		if (graph[i].size() == 1) {
			is_lef[i] = true;
			if (i != 0) {
				que.push(i);
			}
		}
		else {
			need[i] *= 2;
		}
	}
	while (!que.empty())
	{
		auto pos = que.front(); que.pop();
		auto p = *graph[pos].begin();
		auto add = need[pos] - use[pos];
		if (add<0 || (!is_lef[pos] && add * 2 > need[pos]) || (!is_lef[p] && add * 2 > need[p])) {
			out << "NO" << endl; return 0;
		}
		use[p] += add; use[pos] += add;
		graph[p].erase(pos);
		if (p != 0 && graph[p].size() == 1) {
			que.push(p);
		}
	}
	out << ((need[0] == use[0]) ? ("YES") : ("NO")) << endl;
	return 0;
}
#endif