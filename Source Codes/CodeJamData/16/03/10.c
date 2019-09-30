#include<stdio.h>

int main() {
	int i,j,k,n,m,N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		printf("Case #%d:\n",++cs);
		for(i=0;i<m;i++) {
			for(j=0;j<n;j++) {
				if (j==0 || j==n-1) putchar('1');
				else putchar('0'+((i>>((j-1)/2))&1));
			}
			for(j=2;j<=10;j++) printf(" %d",j+1);
			puts("");
		}
	}
	return 0;
}
