#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int INF = (int)1e8;
const int V = (int)1e4;
const int E = 7 * V + 10;

struct Edge
{
	int to, cap, flow;

	Edge() : to(), cap(), flow() {}
	Edge(int _to, int _cap) : to(_to), cap(_cap), flow(0) {}
};

vector<int> g[V];
Edge ed[E];
int edSz;
int n, m;
int S = 0, T = 1;
int dist[V];
int q[V];
int topQ;
int idx[V];
map<string, int> mapchik;
string str;

int getIndex(string s)
{
	if (mapchik.count(s) == 0)
	{
		mapchik[s] = m;
		return m++;
	}
	return mapchik[s];
}

void clearAll()
{
	mapchik.clear();
	for (int i = 0; i < n; i++)
		g[i].clear();
	edSz = 0;
	m = 0;
	return;
}

void addEdge(int v, int to, int cap)
{
	g[v].push_back(edSz);
	ed[edSz++] = Edge(to, cap);
	g[to].push_back(edSz);
	ed[edSz++] = Edge(v, 0);
	return;
}

void read()
{
	cin >> n;
	getline(cin, str);

	getline(cin, str);
	str += " ";
	int len = str.length();
	int l = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ') continue;
		if (l == i)
		{
			l++;
			continue;
		}
		string st = str.substr(l, i - l);
		l = i + 1;
		int v = getIndex(st);
		addEdge(S, n + 2 * v, INF);
	}

	getline(cin, str);
	str += " ";
	len = str.length();
	l = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ') continue;
		if (l == i)
		{
			l++;
			continue;
		}
		string st = str.substr(l, i - l);
		l = i + 1;
		int v = getIndex(st);
		addEdge(n + 2 * v + 1, T, INF);
	}

	for (int u = 2; u < n; u++)
	{
		
		getline(cin, str);
		str += " ";
		len = str.length();
		l = 0;
		for (int i = 0; i < len; i++)
		{
			if (str[i] != ' ') continue;
			if (l == i)
			{
				l++;
				continue;
			}
			string st = str.substr(l, i - l);
			l = i + 1;
			int v = getIndex(st);
			addEdge(u, n + 2 * v, INF);
			addEdge(n + 2 * v + 1, u, INF);
		}

	}

	for (int i = 0; i < m; i++)
		addEdge(n + 2 * i, n + 2 * i + 1, 1);
	n += 2 * m;

	return;
}

bool bfs()
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[S] = 0;
	q[0] = S;
	topQ = 1;
	for (int k = 0; k < topQ; k++)
	{
		int v = q[k];
		for (int eid : g[v])
		{
			Edge e = ed[eid];
			if (e.cap == e.flow) continue;
			int to = e.to;
			if (dist[to] <= dist[v] + 1) continue;
			dist[to] = dist[v] + 1;
			q[topQ++] = to;
		}
	}

	return dist[T] != INF;
}

int dfs(int v, int flow)
{
	if (v == T || flow == 0) return flow;
	int res = 0;
	for (int &i = idx[v]; i < (int)g[v].size(); i++)
	{
		int eid = g[v][i];
		Edge e = ed[eid];
		int to = e.to;
		if (dist[to] != dist[v] + 1) continue;
		int delta = dfs(to, min(flow, e.cap - e.flow));
		res += delta;
		flow -= delta;
		ed[eid].flow += delta;
		ed[eid ^ 1].flow -= delta;
		if (flow == 0) return res;
	}
	return res;
}

int maxFlow()
{
	int res = 0;
	while(bfs())
	{
		for (int i = 0; i < n; i++)
			idx[i] = 0;
		res += dfs(S, INF);
	}
	return res;
}

void solve()
{
	clearAll();
	read();
	cout << maxFlow() << endl;
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
