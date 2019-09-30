#include <iostream>
#include <cstring>
#include <queue>
#include <cstring>
using namespace std;

const int N = 111;

int x[N], y[N];
int u[N], v[N];

vector <int> edges[N];
int deg[N];
bool vis[N];

int solve(int n)
{
	memset(deg, 0, sizeof(deg));
	for(int i = 1; i <= n; i ++)
		for(auto &v : edges[i])
			deg[v] ++;

	int cnt = 0;
	queue <int> que;
	for(int i = 1; i <= n; i ++)
		if(!vis[i] && deg[i] == 0)
			que.push(i);

	while(!que.empty())
	{
		int cur = que.front();
		que.pop();
		cnt ++;
		for(auto &v : edges[cur])
		{
			deg[v] --;
			if(!vis[v] && deg[v] == 0)
				que.push(v);
		}
	}
	return cnt;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a;
	for(int i = 0; i < a; i ++)
		cin >> x[i] >> y[i];
	cin >> b;
	for(int i = 0; i < b; i ++)
		cin >> u[i] >> v[i];

	int ans = 0;
	for(int k = 0; k < (1 << (2 * b)); k ++)
	{
		bool flag = true;
		for(int i = 0; i < b; i ++)
			if(((k >> (i * 2)) & 3) == 3)
				flag = false;
		if(!flag)
			continue;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i ++)
			edges[i].clear();

		for(int i = 0; i < b; i ++)
		{
			int t = (k >> (i * 2)) & 3;
			if(t == 0)
				vis[u[i]] = true;
			else if(t == 1)
				vis[v[i]] = true;
			else
				edges[u[i]].push_back(v[i]);
		}
		for(int i = 0; i < a; i ++)
			edges[y[i]].push_back(x[i]);
		ans = max(ans, solve(n));
	}
	cout << ans << '\n';
	return 0;
}