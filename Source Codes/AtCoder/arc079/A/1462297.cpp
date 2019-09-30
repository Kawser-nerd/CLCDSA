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


#include <queue>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <iterator>

using COST_T = uint32_t;
constexpr uint32_t N_MAX = 200000;
constexpr COST_T INF = 1000 * 1000 * 1000 + 1000;//std::numeric_limits<double>::infinity()

#if defined(_MSC_VER) && defined(_DEBUG)
//static_assert(false, "???????????????????");
#endif

struct edge {
	uint32_t to;
	COST_T cost;
	edge() {}
	edge(uint32_t to_, COST_T cost_)
		:to(to_), cost(cost_) {}
};
std::vector<edge> graph[N_MAX];

//??????
COST_T D[N_MAX];
void Dijkstra(uint32_t s)
{
	using P = std::pair<COST_T, uint32_t>;//cost pos
	std::priority_queue<P, std::vector<P>, std::greater<>> que;
	std::fill(std::begin(D), std::end(D), INF);

	D[s] = 0;
	que.emplace(0, s);
	while (!que.empty())
	{
		auto p = que.top(); que.pop();
		const auto& nowpos = p.second;
		const auto& nowcost = p.first;
		if (D[nowpos] < nowcost) { continue; }

		//for (int32_t to = 0; to < N; ++to)
		//{
		//	auto cost = nowcost + graph[nowpos][to];
		//	if (cost < D[to]) {
		//		D[to] = cost;
		//		que.emplace(D[to], to);
		//	}
		//}

		for (const auto& e : graph[nowpos])
		{
			auto cost = nowcost + e.cost;
			if (cost < D[e.to]) {
				D[e.to] = cost;
				que.emplace(cost, e.to);
			}
		}

	}
}



int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	int M;
	in >> N>>M;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		in >> a >> b;
		--a; --b;
		graph[a].emplace_back(b, 1);
		graph[b].emplace_back(a, 1);
	}
	Dijkstra(0);
	if (D[N - 1] > 2) {
		out << "IM";
	}
	out << "POSSIBLE" << endl;

	return 0;
}
#endif