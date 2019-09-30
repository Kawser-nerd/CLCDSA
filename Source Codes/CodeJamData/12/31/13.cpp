#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1000 + 10;

vector<int> e[maxn];
bool used[maxn];
int q[maxn], deg[maxn];
int n;

bool bfs(int x) {
	memset(used, 0, sizeof(used));
	used[x] = 1;
	q[0] = x;
	for (int h = 0, t = 1; h < t; ++h) {
		int u = q[h];
		for (int sz = e[u].size(), i = 0; i < sz; ++i) {
			int v = e[u][i];
			if (!used[v]) {
				used[v] = 1;
				q[t++] = v;
			}
			else return 1;
		}
	}
	return 0;
}

bool check() {
	for (int i = 0; i < n; ++i)
		if (bfs(i)) return 1;
	return 0;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d", &n);
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < n; ++i) e[i].clear();
		for (int i = 0; i < n; ++i) {
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				int x;
				scanf("%d", &x);
				--x;
				e[i].push_back(x);
				++deg[x];
			}
		}

		printf("Case #%d: %s\n", nCase, check() ? "Yes" : "No");
	}

	return 0;
}
