#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cfloat>
#include <cmath>
#include <functional>

using namespace std;

#define EPSILON 1e-5
#define INF (INFINITY/3)


class Edge {
public:
	int lv;
	int rv;
	double w;
	Edge(int lv, int rv, double w) {
		this->lv = lv;
		this->rv = rv;
		this->w = w;
	}

	Edge(int r, int l) : Edge(r, l, 1) {}
};

class Graph {
public:
	vector<int> vs;
	vector<Edge> es;

	Graph(vector<int>& vs, vector<Edge>& es) { this->vs = vs; this->es = es; }
	Graph(int n, vector<Edge>& es) { this->vs = vector<int>(n, 0); this->es = es; }
	Graph(int n) { this->vs = vector<int>(n, 0); this->es = vector<Edge>(); }

	//????
	//adjacency()[i][j]??(i,j)?????????????????INF
	vector<vector<double> > adjacency() {
		int n = vs.size();
		int m = es.size();
		vector<vector<double> > adj(n, vector<double>(n, DBL_MAX));

		for (int i = 0;i < m;i++) {
			adj[es[i].lv][es[i].rv] = es[i].w;
			adj[es[i].rv][es[i].lv] = es[i].w;
		}
		return adj;
	}

	//???s?????????
	vector<double> dijkstra(int s) {
		int n = vs.size();
		vector<double> dists(n, INF);
		vector<vector<double> > adj = adjacency();
		vector<int> que;

		for (int i = 0;i < n;i++) {
			dists[i] = ((i == s) ? 0 : INF);
			que.push_back(i);
		}

		while (!que.empty()) {
			int argminD = -1;
			double minD = INF;
			int u = -1;
			for (int i = 0;i < que.size();i++) {
				if (dists[que[i]] < minD) {
					minD = dists[que[i]];
					argminD = i;
					u = que[i];
				}
			}
			que.erase(que.begin() + argminD);

			for (int i = 0;i < n;i++) {
				double alt = dists[u] + adj[i][u];

				if (alt < dists[i]) {
					dists[i] = alt;
				}
			}
			int a = 0;
		}

		return dists;
	}


};

class Main {
public:
	int getAns(Graph& g) {
		int minDist = INT_MAX;
		for (int i = 0;i < g.vs.size();i++) {
			int maxDist = 0;
			vector<double> dists = g.dijkstra(i);
			for (int j = 0;j < g.vs.size();j++) {
				maxDist = max(maxDist, (int)dists[j]);
			}

			minDist = min(minDist, maxDist);
		}
		return minDist;
	}
};


int main()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);
	Main main;

	for (int i = 0;i < m;i++) {
		int l, r;
		double w;
		cin >> l >> r >> w;
		g.es.push_back(Edge(r - 1, l - 1, w));
	}

	cout << main.getAns(g) << endl;

	return 0;
}