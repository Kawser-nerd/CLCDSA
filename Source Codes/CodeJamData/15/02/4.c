#include<stdio.h>

int a[1024];

int main() {
	int cs=0,N,n,i,ret,mx,t,j;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=mx=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (a[i]>mx) mx=a[i];
		}
		ret=1000000;
		for(i=1;i<=mx;i++) {
			for(j=t=0;j<n;j++) t+=(a[j]+i-1)/i-1;
			if (t+i<ret) ret=t+i;
		}
		printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}