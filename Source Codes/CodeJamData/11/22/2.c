#include<stdio.h>

int a[256][2];
int n,m;

int cal(double t) {
	int i,j;
	double last=-1e100,pos;
	for(i=0;i<n;i++) for(j=0;j<a[i][1];j++) {
		pos=a[i][0]-t;
		if (last+m>pos) pos=last+m;
		if (pos-a[i][0]>t+1e-12) return 0;
		last=pos;
	}
	return 1;
}

int main() {
	int N,cs=0,i;
	double l,r;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++) scanf("%d %d",&a[i][0],&a[i][1]);
		for(l=0,r=1e20,i=0;i<300;i++) {
			if (cal((l+r)*0.5)) r=(l+r)*.5; else l=(l+r)*.5;
		}
		printf("Case #%d: %.10lf\n",++cs,(l+r)*.5);
	}
	return 0;
}
