#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;

int n;
int val[MAXN];
int dep[MAXN];
vector<int> E[MAXN];

int level;
int ansFlag = true;
int l[MAXN], r[MAXN];
int ans[MAXN];

void DFS1(int u, int pre){
	if (val[u] >= 0){
		ansFlag &= ((dep[u] ^ val[u]) & 1) == level;
		l[u] = val[u], r[u] = val[u];
	}
	else
		l[u] = -1E7, r[u] = 1E7;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		dep[v] = dep[u] + 1;
		DFS1(v, u);

		l[u] = max(l[u], l[v] - 1);
		r[u] = min(r[u], r[v] + 1);
	}
	if (l[u] > r[u])
		ansFlag = false;
}

void DFS2(int u, int pre){
//	printf("%d %d %d, %d\n", u, l[u], r[u], ans[u]);
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		ans[v] = ans[u] + 1 <= r[v] ? ans[u] + 1 : ans[u] - 1;
		DFS2(v, u);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		val[i] = -1;
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int K;
	scanf("%d", &K);
	int root = -1;
	for (int v, p, i = 0; i < K; ++i){
		scanf("%d%d", &v, &p);
		val[v] = p;
		root = v;
	}
	level = val[root] & 1;
	DFS1(root, 0);
	if (ansFlag){
		ans[root] = val[root];
		DFS2(root, 0);
		puts("Yes");
		for (int i = 1; i <= n; ++i)
			printf("%d\n", ans[i]);
	}
	else
		puts("No");
	return 0;
}