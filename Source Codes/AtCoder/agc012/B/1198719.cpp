#include<stdio.h>
#include<vector>
#include<queue>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

vector<int>E[100000];
int v[100000], d[100000], c[100000];
int c1[100000], c2[100000];
int d1[100000];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	rep(i, m) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		E[a].push_back(b); E[b].push_back(a);
	}
	int q; scanf("%d", &q);
	rep(i, q) {
		scanf("%d%d%d", &v[i], &d[i], &c[i]); v[i]--;
	}
	for (int i = q - 1; i >= 0; i--) {
		queue<int>que;
		memset(d1, -1, sizeof(d1));
		d1[v[i]] = d[i];
		if (c1[v[i]] == 0)c1[v[i]] = c[i];
		if (c2[v[i]] >= d1[v[i]])continue;
		c2[v[i]] = d1[v[i]];
		if (d1[v[i]])que.push(v[i]);
		while (!que.empty()) {
			int p = que.front(); que.pop();
			for (int u : E[p]) {
				if (d1[u] != -1)continue;
				d1[u] = d1[p] - 1;
				if (c1[u] == 0)c1[u] = c[i];
				if (c2[u] >= d1[u])continue;
				c2[u] = d1[u];
				if (d1[u])que.push(u);
			}
		}
	}
	rep(i, n)printf("%d\n", c1[i]);
}