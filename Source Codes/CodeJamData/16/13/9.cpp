#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;


int Case, ans;
int T, n, x[10000], a[10000];
vector <int> ve[10000];
bool used[10000];

void dfs(int now, int tar, int l) {
	if (now == tar) {
		ans = max(ans, l);
	}
	if (used[now])
		return ;
	used[now] = true;
	if (tar == now)
		return ;
	dfs(a[now], tar, l + 1);
}

int dfs(int k, int fa, int l, int xx) {
	x[xx] = max(x[xx], l);
	for (int i = 0; i < (int) ve[k].size(); i++)
		if (ve[k][i] != fa)
			dfs(ve[k][i], k, l + 1, xx);
}

int main() {
	// freopen("C-small-attempt0.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			ve[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ve[a[i]].push_back(i);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			used[i] = true;
			dfs(a[i], i, 1);
			memset(used, false, sizeof used);
		}
		int tot = 0;
		for (int i = 1; i <= n; i++)
			if (a[a[i]] == i) {
				x[i] = 0;
				dfs(i, a[i], 0, i);
				tot += 1;
				tot += x[i];
			}else x[i] = -10000;
		ans = max(ans, tot);
		printf("Case #%d: %d\n", ++Case, ans);
	}
}
