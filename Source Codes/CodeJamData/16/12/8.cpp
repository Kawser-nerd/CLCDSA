#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[2513];

void solve() {
	memset(cnt,0,sizeof cnt);
	scanf("%d",&n);
	for (int i=0;i<2*n-1;i++) {
		int x;
		for (int j=0;j<n;j++) {
			scanf("%d",&x);
			cnt[x]+=1;
		}
	}
	for (int i=0;i<2513;i++) if (cnt[i]%2==1) printf("%d ",i);
	printf("\n");
}

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		printf("Case #%d: ",t);
		solve();
	}

	return 0;
}
