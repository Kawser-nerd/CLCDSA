#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

struct Edge {
	int y; Edge *next;
	Edge(int y, Edge *next):y(y), next(next){}
}*a[MAXN];

int n, f[MAXN], size[MAXN];

vector<int> tmp;

inline void Dfs(int u, int father) {
	int cnt = 0; size[u] = 1;
	for (Edge *p = a[u]; p; p = p->next) if (p->y != father) {
		Dfs(p->y, u);
		size[u] += size[p->y];
		cnt++;
	}
	tmp.clear();
	for (Edge *p = a[u]; p; p = p->next) if (p->y != father) tmp.push_back(size[p->y] - f[p->y]);
	if (tmp.size() < 2) f[u] = size[u] - 1; else {
		sort(tmp.rbegin(), tmp.rend());
		f[u] = (size[u] - 1) - tmp[0] - tmp[1];
	}
}

int main(void) {
	freopen("B-large.in", "r", stdin);
	freopen("out", "w", stdout);
	int kase; scanf("%d", &kase); for (int _ = 1; _ <= kase; _++) {
		printf("Case #%d: ", _); memset(a, 0, sizeof a);
		scanf("%d", &n); 
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			a[x] = new Edge(y, a[x]);
			a[y] = new Edge(x, a[y]);
		}
		int Ans = 1000000;
		for (int i = 1; i <= n; i++) {
			Dfs(i, 0);
			Ans = min(Ans, f[i]);
		}
		printf("%d\n", Ans);
	}
	return 0;
}

