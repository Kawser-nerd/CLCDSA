#include <stdio.h>

/* return next k-selection (bitmask) */
int snoob(int x) {
	int s=x&-x, r=x+s, o=x^r;
	o=(o>>2)/s;
	return r|o;
}

void solve() {
	double p[200],best=0,cur,q[200],P;
	int n,k,i,mask,j,yes,no;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++) scanf("%lf",&p[i]);
	mask=(1<<k)-1;
	do {
		for(i=j=0;i<n;i++) if(mask&(1<<i)) q[j++]=p[i];
		cur=0;
		for(i=0;i<(1<<k);i++) {
			yes=no=0;
			for(P=1,j=0;j<k;j++) if(i&(1<<j)) yes++,P*=q[j];
			else no++,P*=1-q[j];
			if(yes==no) cur+=P;
		}
		if(best<cur) best=cur;
		mask=snoob(mask);
	} while(mask<(1<<n));
	printf("%.10f\n",best);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
