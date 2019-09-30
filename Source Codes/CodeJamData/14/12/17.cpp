#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> g[1010];

bool vis[1010];
int f(int x, int pa) {
	int deg = g[x].size();
	if(pa != -1) deg--;

	if(deg < 2) return 1;

	vector<int> v;
	for(int i = 0; i < g[x].size(); ++i) {
		if(g[x][i] != pa)
			v.push_back(f(g[x][i], x));
	}

	sort(v.begin(), v.end());
	return v[v.size()-1] + v[v.size() - 2] + 1;
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) g[i].clear();
		for(int i = 0, a, b; i < n - 1; ++i) {
			scanf("%d%d", &a, &b);
			a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		int ans = n - 1;
		for(int i = 0; i < n; ++i) {
			memset(vis, 0, sizeof vis);
			int x = f(i, -1);
			//printf("%d %d\n", i+1, n-x);
			ans = min(ans, n -  x);
		}
		printf("Case #%d: ", kase);
		printf("%d\n", ans);
	}
	return 0;
}
