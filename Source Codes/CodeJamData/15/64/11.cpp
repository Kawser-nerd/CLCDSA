#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105 << 1, M = N * N;

int n, m, k;

#define next NEXT

int top, head[N], next[M], to[M], c[M];

vector<int> edge[N];

void addedge(int u, int v, int cap) {
	to[top] = v, next[top] = head[u], c[top] = cap, head[u] = top++;
}

int source, target, dis[N], gap[N];

bool over;

const int INF = 1000000000;

int go(int u, int delta) {
	if (u == target) {
		return delta;
	}

	int t = delta, tmp;

	for (int i = head[u]; ~i; i = next[i]) {
		if (c[i]) {
			int v = to[i];
			if (dis[v] == dis[u] - 1) {
				tmp = min(t, c[i]);
				tmp = go(v, tmp);
				t -= tmp, c[i] -= tmp, c[i ^ 1] += tmp;
				if (over || t == 0) {
					return delta - t;
				}
			}
		}
	}

	if ((--gap[dis[u]++]) == 0) {
		over = true;
	}
	++gap[dis[u]];

	return delta - t;
}

int cut() {
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	int ret = 0;
	over = false;
	while (!over && dis[source] < 2 * n) {
		ret += go(source, INF);
	}
	return ret;
}

int vis[N], stamp;

int dist() {
	queue<int> q;
	++stamp;
	q.push(0);
	dis[0] = 0;
	vis[0] = stamp;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i];
			if (vis[v] != stamp) {
				vis[v] = stamp;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[n - 1];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		top = 0;
		memset(head, -1, sizeof(head));
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i) {
			edge[i].clear();
		}
		source = n, target = n - 1;
		for (int i = 1; i < n - 1; ++i) {
			addedge(i, i + n, 1);
			addedge(i + n, i, 0);
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int d = dist();
		for (int u = 0; u < n; ++u) {
			for (int i = 0; i < (int)edge[u].size(); ++i) {
				int v = edge[u][i];
				if (dis[v] == dis[u] + 1) {
					addedge(u + n, v, INF); 
					addedge(v, u + n, 0);
				}
			}
		}
		--k;
		static int id = 0;
		int c = cut();
		cerr << c << ' ' << d << ' ' << k << ' ' << endl;
		cerr << d + 1 + (c <= k) << endl;
		printf("Case #%d: %d\n", ++id, d + 1 + (c <= k));
	}
	return 0;
}
