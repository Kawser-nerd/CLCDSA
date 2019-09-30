#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

struct edge
{
	int to;
	long long cost;
	edge(int to_, long long cost_) :
		to(to_), cost(cost_) {}
};
const long long INF = 123456789012345;
using P = pair<long long, int>;//first:cost,second:vertice
void dijkstra(vector<edge>graph_[], long long dist[], int n_, int s_)
{
	priority_queue<P, vector<P>, greater<P>>que;
	que.push({ 0,s_ });
	fill(dist, dist + n_, INF);
	dist[s_] = 0ll;
	while (!que.empty())
	{
		auto q = que.top();
		que.pop();
		long long thd = q.first;
		int thv = q.second;
		if (thd > dist[thv])
		{
			continue;
		}
		for (auto ed : graph_[thv])
		{
			if (dist[ed.to] > ed.cost + thd)
			{
				dist[ed.to] = ed.cost + thd;
				que.push({ dist[ed.to],ed.to });
			}
		}
	}
}

vector<edge>graph[5000000];
LL dist[5000000];
map<pair<int, int>, int>vecset;
int n, m;

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		vecset[make_pair(i, 0)] = i;
	for (int i = 0; i < m; ++i)
	{
		int p, q, c;
		cin >> p >> q >> c;
		--p; --q;
		int f1 = 0, f2 = 0;
		if (!vecset.count(make_pair(p, c)))
		{
			f1 = vecset[make_pair(p, c)] = vecset.size();
			//????????0
			graph[f1].push_back(edge(p, 0));
			//????????1
			graph[p].push_back(edge(f1, 1));
		}
		else
		{
			f1 = vecset[make_pair(p, c)];
		}
		if (!vecset.count(make_pair(q, c)))
		{
			f2 = vecset[make_pair(q, c)] = vecset.size();
			//????????0
			graph[f2].push_back(edge(q, 0));
			//????????1
			graph[q].push_back(edge(f2, 1));
		}
		else
		{
			f2 = vecset[make_pair(q, c)];
		}
		//?????0
		graph[f1].push_back(edge(f2, 0));
		graph[f2].push_back(edge(f1, 0));
	}
	dijkstra(graph, dist, vecset.size(), 0);
	if (dist[n - 1] >= INF)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << dist[n - 1] << endl;
	return 0;
}