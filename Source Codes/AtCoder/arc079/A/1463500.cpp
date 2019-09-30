//I Guds namn
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAXN = 2 * 100 * 1000 + 13;

ll d[MAXN];

queue<ll> bfsq;

vector<ll> adj[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    for(ll i = 0;i < m;i++)
    {
	ll u, v; cin >> u >> v; u--; v--;
	adj[u].push_back(v); adj[v].push_back(u);
    }
    d[0] = 0;
    bfsq.push(0);
    while(bfsq.size())
    {
	ll u = bfsq.front(); bfsq.pop();
	for(auto v : adj[u])
	{
	    if(d[v] <= 0)
	    {
		d[v] = d[u] + 1;
		bfsq.push(v);
	    }
	}
    }
    if(d[n - 1] == 2)
    {
	cout << "POSSIBLE";
    }
    else
    {
	cout << "IMPOSSIBLE";
    }
    cout << endl;
    return 0;
}