#include <stdio.h>

int n;
int m[1000];

void solve() {
	static int caseno=1;
	int i,a=0,b=0,hi=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&m[i]);
	for(i=1;i<n;i++) if(m[i-1]>m[i]) a+=m[i-1]-m[i];
	for(i=1;i<n;i++) if(hi<m[i-1]-m[i]) hi=m[i-1]-m[i];
	for(i=0;i<n-1;i++) if(m[i]<hi) b+=m[i]; else b+=hi;
	printf("Case #%d: %d %d\n",caseno++,a,b);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
