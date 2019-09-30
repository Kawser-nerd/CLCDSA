#include<stdio.h>

int main() {
	int N,cs=0,n;
	long long p,y,z,s,t;
	for(scanf("%d",&N);N--;) {
		scanf("%d %lld",&n,&p);
		s=1LL<<n;
		if (p==s) {
			printf("Case #%d: %lld %lld\n",++cs,s-1,s-1);
			continue;
		}
		y=z=0;
		for(s=2,t=1LL<<(n-1);s<=p;s<<=1,t>>=1) z|=t;
		for(p--,s=1LL<<(n-1),t=2;p&s;s>>=1,t<<=1) y|=t;
		printf("Case #%d: %lld %lld\n",++cs,y,z);
	}
	return 0;
}
