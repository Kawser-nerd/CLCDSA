#include <bits/stdc++.h>
using namespace std;

int n;
int adj[1013];
bool vis[1013];
int best[1013];

void solve() {
	memset(vis,0,sizeof vis);
	scanf("%d",&n);
	fill(best,best+n+1,1);
	for (int i=1;i<=n;i++) scanf("%d",&adj[i]);
	int cyc = 0;
	for (int i=1;i<=n;i++) {
		int pos = i;
		int len = 0;
		memset(vis,0,sizeof vis);
		while (!vis[pos]) {
			len+=1;
			vis[pos] = 1;
			pos = adj[pos];
		}
		if (pos==i) cyc = max(cyc,len);
		if (adj[adj[pos]]==pos) best[pos] = max(best[pos],len-1);
	}
	int ans = 0;
	for (int i=1;i<=n;i++) if (adj[adj[i]]==i) {
		ans+=best[i]+best[adj[i]];
	}
	ans = max(ans/2,cyc);
	printf("%d\n",ans);
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		printf("Case #%d: ",t);
		solve();
	}

	return 0;
}
