#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100;

vector <int> f[MAXN];
int m, n;
int cnt[MAXN];

void dfs(int root) {
	int i, j, k;
	++cnt[root];
	for (i=0; i<f[root].size(); ++i) {
		dfs(f[root][i]);
	}
}

int main() {
	int i, j, k;
	int tc, cn(0);

	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) f[i].clear();
		for (i=0; i<n; ++i) {
			scanf("%d", &m);
			for (j=0; j<m; ++j) {
				scanf("%d", &k);
				f[i].push_back(k-1);
			}
		}
		printf("Case #%d: ", ++cn);
		for (i=0; i<n; ++i) {
			memset(cnt, 0, sizeof(cnt));
			dfs(i);
			for (j=0; j<n; ++j) if (cnt[j] >= 2) break;
			if (j < n) break;
		}
		if (i < n) puts("Yes");
		else puts("No");
	}
	return 0;
}