#include <stdio.h>
#include <math.h>

int n,k;
double p[55];
double u;



void solve() {
	double lo,hi,mid,used,res;
	int i,j;
	scanf("%d %d %lf",&n,&k,&u);
	if(k!=n) printf("sanity error");
	for(i=0;i<n;i++) scanf("%lf",&p[i]);
	lo=0;hi=1;
	for(i=0;i<1000;i++) {
		mid=(lo+hi)/2;
		used=0;
		for(j=0;j<n;j++) if(p[j]<mid) used+=mid-p[j];
		if(used<u) lo=mid;
		else hi=mid;
	}
	res=1;
	for(i=0;i<n;i++) if(p[i]<lo) res*=lo; else res*=p[i];
	printf("%.10f\n",res);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
