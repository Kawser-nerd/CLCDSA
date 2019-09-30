#include <stdio.h>

void solve() {
	double best=1e100,tid;
	int d,n,d2,f;
	scanf("%d %d",&d,&n);
	while(n--) {
		scanf("%d %d",&d2,&f);
		tid=(d-d2)/(double)f;
		if(best>d/tid) best=d/tid;
	}
	printf("%.10f\n",best);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
