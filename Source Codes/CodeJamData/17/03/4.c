#include<stdio.h>

int main() {
	int N,cs=0;
	long long n,m;
	long long a,b0,b1,c,d0,d1,r,r1,r2;
	for(scanf("%d",&N);N--;) {
		scanf("%I64d %I64d",&n,&m);
		m--;
		a=n,b0=1,b1=0;
		while(m>=b0+b1) {
			m-=b0+b1;
			d0=d1=0;
			c=a/2;
			if (a%2) d0+=b0*2+b1,d1+=b1; else d0+=b0,d1+=b0+b1*2;
			a=c,b0=d0,b1=d1;
		}
		if (m>=b0) r=a-1; else r=a;
		if (r&1) r1=r2=r/2; else r1=r/2,r2=r/2-1;
		printf("Case #%d: %I64d %I64d\n",++cs,r1,r2);
	}
	return 0;
}