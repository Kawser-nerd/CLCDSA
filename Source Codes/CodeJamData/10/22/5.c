#include<stdio.h>

int X[64],V[64];
int n,k,b,t;

int main() {
	int N,cs=0,i,j,ret;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d %d",&n,&k,&b,&t);
		for(i=0;i<n;i++) scanf("%d",&X[i]);
		for(i=0;i<n;i++) scanf("%d",&V[i]);
		for(ret=i=0,j=n-1;i<k;i++) {
			while(j>=0 && X[j]+V[j]*t<b) j--;
			if (j<0) break;
			ret+=n-i-1-j;
			j--;
		}
		if (i<k) printf("Case #%d: IMPOSSIBLE\n",++cs);
		else printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}
