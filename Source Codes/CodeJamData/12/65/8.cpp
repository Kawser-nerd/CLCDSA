#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>

using namespace std;

const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int maxn = 12;

int n;
int go[maxn][2];

bool vis[10][1<<10];

int calc(int now, int mask) {
	if(now == n-1) return 0;

	if(vis[now][mask]) return -1;
	vis[now][mask] = true;

	int res = calc(go[now][(mask>>now)&1], mask^(1<<now));

	if(res == -1) return -1;
	else return res + 1;
}

int main() {
	freopen("E-small-attempt0.in", "r", stdin);
	freopen("E-small-attempt0.out", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &n);
		for(int i=0; i<n-1; i++) {
			scanf("%d%d", &go[i][0], &go[i][1]);
			go[i][0]--;
			go[i][1]--;
		}

		memset(vis, 0, sizeof(vis));
		int u = calc(0, 0);

		if(u == -1) printf("Case #%d: Infinity\n", test);
		else printf("Case #%d: %d\n", test, u);
	}
	return 0;
}