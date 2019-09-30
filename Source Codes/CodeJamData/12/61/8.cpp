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

const int maxn = 105;

struct zombie {
	int x, y, m;
}z[maxn];

struct state {
	int id, t;
}s[maxn*1005];

const int cmp(const state &a, const state &b) {
	return z[a.id].m + a.t < z[b.id].m + b.t;
}

int go(int X1, int Y1, int X2, int Y2) {
	return max(abs(X1 - X2), abs(Y1 - Y2)) * 100;
}

int n, cnt;
int dp[maxn][1005];
int ans;

void update(int t, int id, int v) {
	if(t < z[id].m) t = z[id].m;
	if(t > z[id].m + 1000) return;

	t -= z[id].m;

	if(dp[id][t] < v) dp[id][t] = v;
	if(ans < v) ans = v;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d%d%d", &z[i].x, &z[i].y, &z[i].m);
		}
		cnt = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<=1000; j++) {
				s[cnt].id = i;
				s[cnt].t = j;
				cnt++;
			}
		}

		sort(s, s+cnt, cmp);

		memset(dp, -1, sizeof(dp));
		ans = 0;

		for(int next = 0; next < n; next++) {
			update(go(0, 0, z[next].x, z[next].y), next, 1);
		}

		for(int i=0; i<cnt; i++) {
			int id = s[i].id;
			int t = s[i].t;

			if(dp[id][t] == -1) continue;

			for(int next=0; next<n; next++) {
				if(next == id) continue;
				update(t + z[id].m + max(750, go(z[id].x, z[id].y, z[next].x, z[next].y)), next, dp[id][t] + 1);
			}
		}
		
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}