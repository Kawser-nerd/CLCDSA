#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <functional>
#include <string.h>

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))






struct edge { 
	int dst;
	ll cost;
	edge (int dst, ll cost){
		this->dst= dst; this->cost=cost;
	}
};

typedef vector<edge> edges;


class Dijkstra {

typedef pair<ll, int>P;
#define INF (1LL<<61)

public:
	vector<ll> dist;
	Dijkstra(int n) {
		dist.resize(n);
	}
	void solve(vector<edges> &G) {
		fill(all(dist), INF);
		dist[0] = 0;

		priority_queue<P, vector<P>, greater<P> > q;
		q.push(make_pair(0, 0));

		while (q.size()) {
			pair<ll, int> p = q.top(); q.pop();
			int v = p.second;
			ll d = p.first;
			if (d > dist[v])
				continue;
			rep(i, G[v].size()) {
				edge e = G[v][i];
				if (dist[e.dst] > (dist[v] + e.cost)) {
					dist[e.dst] = dist[v] + e.cost;
					q.push(make_pair(dist[e.dst], e.dst));
				}
			}
		}
	}
};

int n, m, t;
int A[100005];
vector<edges> g, rg;

int main(){
	scanf("%d %d %d ", &n, &m, &t);
	g.resize(n); rg.resize(n);//m?????????
	rep(i, n) {
		scanf("%d ", &A[i]);
	}
	int a, b, c;
	rep(i, m) {
		scanf("%d %d %d ", &a, &b, &c); a--; b--;
		g[a].push_back(edge(b, c));
		rg[b].push_back(edge(a, c));
	}

	Dijkstra cl(n),cr(n);
	cl.solve(g);
	cr.solve(rg);

	ll ans = -1LL;
	rep(i, n) {
		ans = max(max(((ll)t - (cl.dist[i] + cr.dist[i])), 0LL)*(ll)A[i], ans);
	}
	cout << ans << endl;
	return 0;
}