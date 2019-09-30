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
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

int32_t N,M;
char S[200100];
int32_t flag[200000][2];
std::vector<int> graph[200000];

bool deleted[200000];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N >> M;
	in >> S;
	for (int32_t i = 0; i < N; i++)
	{
		S[i] -= 'A';
	}
	for (int32_t i = 0; i < M; i++)
	{
		int a, b;
		in >> a >> b;
		--a; --b;

		graph[a].emplace_back(b);
		graph[b].emplace_back(a);

		++flag[a][S[b]];
		++flag[b][S[a]];
	}

	std::queue<int> que;
	for (int32_t i = 0; i < N; i++)
	{
		if (flag[i][0] <= 0 || flag[i][1] <= 0) {
			deleted[i] = true;
			que.push(i);
		}
	}
	while (!que.empty())
	{
		auto v = que.front(); que.pop();

		for (auto& t : graph[v]) {
			--flag[t][S[v]];
			if (flag[t][S[v]] <= 0 && !deleted[t]) {
				deleted[t] = true;
				que.push(t);
			}
		}
	}

	for (int32_t i = 0; i < N; i++)
	{
		if (!deleted[i]) {
			out << "Yes" << endl;
			return 0;
		}
	}
	

	out << "No" << endl;
	return 0;
}
#endif