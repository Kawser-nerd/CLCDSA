#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const double eps = 1e-8;

const ll INF = 1e15;

typedef ll Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int main(){
	ll N, M;
	string s;
	cin >> N >> M >> s;
	vector<ll> alive(N);
	vector<ll> blive(N);
	Graph g(N);
	for (int i = 0;i < M;i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(Edge(a, b, 1));
		if (a != b)
			g[b].push_back(Edge(b, a, 1));
	}
	queue<ll> dead;
	vector<ll> isdead(N);
	ll num = N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < g[i].size();j++) {
			ll to = g[i][j].dst;
			if (s[to] == 'A')
				alive[i]++;
			else
				blive[i]++;
		}
		if (alive[i] == 0 || blive[i] == 0) {
			dead.push(i);
			isdead[i] = true;
			num--;
		}
	}
	while (!dead.empty()) {
		ll now = dead.front();
		dead.pop();
		for (int i = 0;i < g[now].size();i++) {
			ll to = g[now][i].dst;
			if (!isdead[to]) {
				if (s[now] == 'A') {
					alive[to]--;
				}
				else {
					blive[to]--;
				}
				if (alive[to] == 0 || blive[to] == 0) {
					dead.push(to);
					isdead[to] = true;
					num--;
				}
			}
		}
	}
	if (num > 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}