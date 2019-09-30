#include<stdio.h>
#include<string.h>

int s[12];

int main() {
	int n,m,N,cs=0,i,j,k;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		memset(s,0,sizeof(s));
		for(m=n,j=0;j<=1000;m+=n,j++) {
			for(k=m;k;k/=10) s[k%10]=1;
			for(i=0;i<10 && s[i];i++);
			if (i>=10) break;
		}
		if (j<=1000) printf("Case #%d: %d\n",++cs,m);
		else printf("Case #%d: INSOMNIA\n",++cs);
	}
	return 0;
}
