#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200000;
bool flag = false;
int n,m; 
bool vis[maxn];
int main()
{
	cin >> n >> m;
	vector<int> E[maxn+5];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(int i=0;i<E[1].size();i++)
		vis[E[1][i]] = true;
	for(int i=0;i<E[n].size();i++)
		if(vis[E[n][i]]) flag = true;
	if(flag) cout << "POSSIBLE\n";
	else cout << "IMPOSSIBLE\n";
}