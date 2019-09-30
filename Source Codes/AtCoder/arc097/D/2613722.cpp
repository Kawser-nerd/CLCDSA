#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
 
const int inf = 1e9;
const int maxN = 1e5 + 5;
int dp[maxN], l[maxN], N, d[maxN], minn = inf, cnt, e, val[maxN];
bool vis[maxN];
char s[maxN];
struct edge{
	int v, fa;
}G[maxN << 1];
 
void add(int u, int v) {
	G[e].v = v; G[e].fa = l[u]; l[u] = e++;
}
 
int que(int i) {
	if(val[i] == 0) return 1;
	return -1; 
}
 
void dfs(int u, int p) {
	//cout << val[u] << ' ' << s[u] << ' ' << u << "***********"<<endl;
	int t1 = inf, t2 = inf;
	for(int i = l[u]; i != -1; i = G[i].fa) {
		int v = G[i].v; if(vis[v] || v == p) continue;
		dfs(v, u);
		if(dp[v] <= t1) t2 = t1, t1 = dp[v];
		else if(dp[v] < t2) t2 = dp[v];
	}
	dp[u] = -1 + que(u);
	if(t1 < inf) dp[u] = min(t1 + que(u) - 1, dp[u]);
	if(t1 < inf && t2 < inf) minn = min(t1 + t2 - 1 + que(u), minn);
	minn = min(minn, dp[u]);
	//cout << u << ' ' << dp[u] << ' ' << "@@@@@@@@@@@@@@@@" << endl;
}
 
int main() {
	scanf("%d", &N); for(int i = 1; i <= N; ++i) l[i] = -1;
	for(int i = 1; i < N; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		add(u, v); add(v, u); d[u]++; d[v]++;
	}
	scanf("%s", s + 1);
	queue<int> q;
	int n = N;
	cnt = 0;
	for(int i = 1; i <= N; ++i) {
		cnt += s[i] == 'W';
		if(d[i] <= 1 && s[i] == 'B') q.push(i), vis[i] = 1, n--;
	}
	while(!q.empty()) {
		int new_ = q.front(); q.pop();
		for(int i = l[new_]; i != -1; i = G[i].fa) {
			int v = G[i].v; if(vis[v]) continue;
			d[v]--;
			if(d[v] <= 1 && s[v] == 'B') q.push(v), vis[v] = 1, n--;
		}
	}
	//cout << n << endl;
	if(n <= 1) {
		cout << n << endl; return 0;
	}
	int ans = 2 * (n - 1);
	for(int i = 1; i <= N; ++i) {
		if(!vis[i]) val[i] = ((s[i] == 'W') + d[i]) % 2, ans += val[i];
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i, -1); break;
		}
	}
	if(minn < 0) ans += minn;
	cout << ans << endl;
}