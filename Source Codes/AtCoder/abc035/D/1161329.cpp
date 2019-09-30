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

int32_t N;


#include <queue>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <iterator>

using COST_T = int64_t;
constexpr uint32_t N_MAX = 100000;
constexpr COST_T INF = 10'000'000'000 + 1000;

#if defined(_MSC_VER) && defined(_DEBUG)
static_assert(false, "???????????????????");
#endif

struct edge {
	uint32_t to;
	COST_T cost;
	edge() {}
	edge(uint32_t to_, COST_T cost_)
		:to(to_), cost(cost_) {}
};
std::vector<edge> graph_go[N_MAX];
std::vector<edge> graph_rev[N_MAX];

//??????
COST_T Dgo[N_MAX];
COST_T Dba[N_MAX];
void Dijkstra(uint32_t s, COST_T (&D)[N_MAX], std::vector<edge>(&graph)[N_MAX])
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


int A[N_MAX];
int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);

	int64_t M,T;
	in >> N>>M>>T;
	for (size_t i = 0; i < N; ++i)
	{
		in >> A[i];
	}
	for (size_t i = 0; i < M; ++i)
	{
		int a, b, c;
		in >> a >> b >> c;
		--a; --b;
		graph_go[a].emplace_back(b, c);
		graph_rev[b].emplace_back(a, c);
	}
	Dijkstra(0, Dgo, graph_go);
	Dijkstra(0, Dba, graph_rev);
	int64_t max = 0;
	for (size_t i = 0; i < N; i++)
	{
		auto time = T - Dba[i] - Dgo[i];
		if (time >= 0) {
			max = std::max(max, time*A[i]);
		}
	}
	out << max << endl;

	return 0;
}
#endif