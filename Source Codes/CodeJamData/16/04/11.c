#include<stdio.h>

int main() {
	int N,cs=0,n,m,k,i,j,t;
	long long r;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d",&n,&m,&k);
		if (m*k<n) {
			printf("Case #%d: IMPOSSIBLE\n",++cs);
			continue;
		}
		printf("Case #%d:",++cs);
		t=(n+m-1)/m;
		for(i=0;i<t;i++) {
			for(r=j=0;j<m;j++) {
				r=r*n+(i*m+j)%n;
			}
			printf(" %lld",r+1);
		}
		puts("");
	}
	return 0;
}
