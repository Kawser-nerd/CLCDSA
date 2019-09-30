#include <stdio.h>

int b;
int tid[1000];
int left[1000];
int N;

/* given time, how many people are cut? */
long long numcut(long long time) {
	long long r=0;
	int i;
	for(i=0;i<b;i++) r+=time/tid[i]+1;
	return r;
}

void solve2() {
	long long lo=0,mid,hi=N*100000LL;
	long long cut;
	int i;
	while(lo<hi) {
		mid=lo+(hi-lo)/2;
		cut=numcut(mid);
		if(cut>=N) hi=mid;
		else lo=mid+1;
	}
	mid=numcut(lo-1);
	for(i=0;i<b;i++) if(lo%tid[i]==0 && ++mid==N) {
		printf("%d\n",i+1);
		break;
	}
}

void solve() {
	static int caseno=1;
	int i;
	scanf("%d %d",&b,&N);
	for(i=0;i<b;i++) scanf("%d",&tid[i]),left[i]=0;
	printf("Case #%d: ",caseno++);
	solve2();
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
