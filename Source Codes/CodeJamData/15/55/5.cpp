#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>


#define MAXN 55

int n,max_d;

int d[MAXN];

inline bool check()
{
	int i;
	for (i=1;i<n;i++) if (d[i]!=d[i+1]) return 0;
	return 1;
}

int ans;

inline void dfs(int cnt,int last_d)
{
	if (check()) {
		ans=cnt;
		return;
	}
	if (cnt>=ans) return;
	for (;last_d<=max_d;last_d<<=1) {
		int i,j;
		for (i=last_d*2-1;i>=0;i--) {
			int x=i;
			int tmp=last_d*2-1;
			for (j=1;j<=n;j++) {
				x=(x+1)&tmp;
				if (x<last_d) {
					if (!d[j]) break;
					--d[j];
				}
			}
			if (j>n) {
				dfs(cnt+1,last_d);
			}
			int tmp1=j;
			x=i;
			for (j=1;j<tmp1;j++) {
				x=(x+1)&tmp;
				if (x<last_d) ++d[j];
			}
		}
	}
}

inline void solve()
{
	scanf("%d%d",&n,&max_d);
	int i;
	for (i=1;i<=n;i++) {
		scanf("%d",d+i);
	}
	ans=233;
	dfs(0,1);
	if (ans==233) {
		puts("CHEATERS!");
	} else {
		printf("%d\n",ans);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for (i=1;i<=T;i++) {
		printf("Case #%d: ",i);
		solve();
	}
}