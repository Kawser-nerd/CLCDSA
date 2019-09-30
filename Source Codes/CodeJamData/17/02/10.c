#include <stdio.h>
typedef unsigned long long u64;
u64 vv[1000];
u64 rec(u64 a, u64 r, int i, int l){
	if(i<0)return r;
	int k = 9;
	r+=k*vv[i];
	while(k>=l){
		if(r<=a){
			u64 v = rec(a,r,i-1,k);
			if(v)return v;
		}
		--k;
		r-=vv[i];
	}
	return 0;
}
int main(){
	int T,Ti;
	vv[0]=1;
	for(Ti=1;Ti<=18;++Ti)vv[Ti]=vv[Ti-1]*10;
	scanf("%d",&T);
	for(Ti=1;Ti<=T;++Ti){
		u64 a,r;
		scanf("%llu",&a);
		r=rec(a,0,18,0);
		printf("Case #%d: %llu\n",Ti,r);
	}
}
