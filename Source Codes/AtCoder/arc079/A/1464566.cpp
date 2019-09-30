#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <stack>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;
#define smin(a, b) (a) = min((a), (b))

int n, m;
vector<int> *g;

inline void init() {
	scanf("%d%d", &n, &m);
	g = new vector<int>[(n + 1)];
	for(int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

queue<int> que;
queue<int> step;
boolean vis[3][200005];
inline void bfs() {
	memset(vis, false, sizeof(vis));
	vis[0][1] = true;
	que.push(1);
	step.push(0);
	while(!que.empty()) {
		int e = que.front();
		int s = step.front();
		que.pop();
		step.pop();
		for(int i = 0; i < (signed)g[e].size(); i++) {
			int& eu = g[e][i];
			if(vis[s + 1][eu])	continue; 
			vis[s + 1][eu] = true;
			if(s != 1) {
				que.push(eu);
				step.push(s + 1);
			}
		}
	}
}

inline void solve() {
	puts((vis[2][n]) ? ("POSSIBLE") : ("IMPOSSIBLE"));
}

int main() {
	init();
	bfs();
	solve();
	return 0;
}