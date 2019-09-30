#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 2000000000;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 2007;
int N, M, P, u[MAX], v[MAX], a[MAX], b[MAX], path[MAX], best[MAX], best2[MAX];
vector<int> graph[MAX];

bool used[MAX];

void dijkstra(int from)
{
	REP(i, N) best[i] = INF;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > manage;
	best[from] = 0;
	manage.push(make_pair(0, from));
	while (!manage.empty())
	{
		pair<int, int> temp = manage.top();
		manage.pop();
		int node = temp.second, cost = temp.first;
		if (cost != best[node]) continue;

		REP(i, graph[node].size())
		{
			int edge = graph[node][i];
			int next = v[edge], cost2 = cost + (used[edge] ? a[edge] : b[edge]);
			if (cost2 < best[next])
			{
				best[next] = cost2;
				manage.push(make_pair(cost2, next));
			}
		}
	}
}

void dijkstra2(int from, int cost)
{
	REP(i, N) best2[i] = INF;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > manage;
	best2[from] = cost;
	manage.push(make_pair(cost, from));
	while (!manage.empty())
	{
		pair<int, int> temp = manage.top();
		manage.pop();
		int node = temp.second, cost = temp.first;
		if (cost != best2[node]) continue;

		REP(i, graph[node].size())
		{
			int edge = graph[node][i];
			int next = v[edge], cost2 = cost + a[edge];
			if (cost2 < best2[next] && cost2 <= best[next])
			{
				best2[next] = cost2;
				manage.push(make_pair(cost2, next));
			}
		}
	}
}

void Solve(int tc)
{
	scanf("%d%d%d", &N, &M, &P);
	REP(i, N) { graph[i].clear(); }
	REP(i, M)
	{
		scanf("%d%d%d%d", &u[i], &v[i], &a[i], &b[i]);
		--u[i], --v[i];
		graph[u[i]].push_back(i);
	}
	int sum = 0;
	REP(i, P)
	{
		scanf("%d", &path[i]);
		--path[i];
		sum += a[path[i]];
	}
	printf("Case #%d: ", tc);

	memset(used, 0, sizeof(used));
	REP(i, P) used[path[i]] = true;
	dijkstra(0);

	if (sum == best[1])
	{
		printf("Looks Good To Me\n");
		return;
	}

	FORD(i, P-1, 0)
	{
		int edge = path[i];
		used[edge] = false;
		sum -= a[edge];
		dijkstra(0);
		int node = u[edge];
		if (sum > best[node])
			continue;
		dijkstra2(node, sum);
		if (best2[1] <= best[1])
		{
			printf("%d\n", edge+1);
			return;
		}
	}
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}