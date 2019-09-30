#include <map>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
#include <stdio.h>

int n;
struct Edge {
	int town;
};

struct EdgeScore {
	int best, secondBest;
	EdgeScore(int best, int secondBest): best(best), secondBest(secondBest) { }
};

vector<pair<Edge, Edge> > c;
map<pair<int,int>, EdgeScore> counts;

void sort(int &a, int &b) {
	if (a>b)
		swap(a,b);
}

int getCount(int town1, int town2) {
	sort(town1, town2);
	auto it = counts.find(make_pair(town1, town2));
	if (it==counts.end())
		return 0;
	return it->second.best;
}

EdgeScore getCount_(int town1, int town2) {
	sort(town1, town2);
	auto it = counts.find(make_pair(town1, town2));
	if (it==counts.end())
		return EdgeScore(-1000000, -1000000);
	return it->second;
}

void setCount(int town1, int town2, int value) {
	sort(town1, town2);
	auto it = counts.find(make_pair(town1, town2));
	if (it==counts.end())
		counts.insert(make_pair(make_pair(town1, town2), EdgeScore(value, -1000000)));
	else {
		if (value>it->second.best) {
			it->second.secondBest = it->second.best;
			it->second.best = value;
		} else if (value>it->second.secondBest)
			it->second.secondBest = value;
	}
}

int runTest() {
	for (int i=c.size()-1; i>2; i--) {
		int newCount = getCount(i+1, c[i].first.town) + getCount(i+1, c[i].second.town) + 1;
		if (getCount(c[i].second.town, c[i].first.town) < newCount) {
			setCount(c[i].second.town, c[i].first.town, newCount);
		}
	}
	int res = 3 + getCount(1,2) + getCount(2,3) + getCount(3,1);
	for (auto it=counts.begin(); it!=counts.end(); it++) {
		int res2 = 2 + it->second.best + it->second.secondBest;
		if (res2>res)
			res = res2;
	}
	return res;
}

#ifdef DO_DFS
vector<vector<int> > graph;
vector<bool> visited;

int dfs(int startTown, int cTown) {
	visited[cTown] = true;
	int best = -100000;
	for (unsigned i=0; i<graph[cTown].size(); i++) {
		int t = graph[cTown][i];
		if (t==startTown)
			if (best<1) best = 1;
		if (!visited[t]) {
			int x = dfs(startTown, t) + 1;
			if (x>best)
				best = x;
		}
	}
	visited[cTown] = false;
	return best;
}

int doDfs() {
	int best = -1;
	for (int startTown=1; startTown<(int)graph.size(); startTown++) {
		int x = dfs(startTown, startTown);
		if (x>best) best = x;
	}
	return best;
}
#endif 

int main() {
	//freopen("in", "r", stdin);
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> n;
		c.resize(n);
#ifdef DO_DFS
		graph.clear();
		graph.resize(n+1);
		graph[1].push_back(2);
		graph[1].push_back(3);
		graph[2].push_back(1);
		graph[2].push_back(3);
		graph[3].push_back(2);
		graph[3].push_back(1);
#endif
		for (int j=3; j<n; j++) {
			int a, b;
			cin >> a >> b;
			c[j].first.town = a;
			c[j].second.town = b;
#ifdef DO_DFS
			graph[j+1].push_back(a);
			graph[j+1].push_back(b);
			graph[a].push_back(j+1);
			graph[b].push_back(j+1);
#endif
		}
#ifdef DO_DFS
		visited = vector<bool>(n+1, false);
#endif

		counts.clear();
#ifdef DO_DFS
		int ans1 = doDfs();
		int ans2 = runTest();
		if (ans1!=ans2) {
			cout << "fuck\n";
		}
#endif
		cout << "Case #" << t << ": " << runTest() << endl;
	}
	return 0;
}
