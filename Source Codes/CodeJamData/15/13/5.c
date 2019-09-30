#include <stdio.h>
#include <math.h>

#define MAXP 444
#define INF 1000000
#define EPS 1e-6

typedef struct {
	int x,y;
} point_t;

point_t p[MAXP],h[MAXP];
int n,hn;

double distsq(double x1,double y1,double x2,double y2) {
	double dx=x1-x2,dy=y1-y2;
	return dx*dx+dy*dy;
}

void convexhull() {
	int i,hix=-INF,loy=-INF,ix=-1;
	int atx,aty;
	double pi=2*acos(0),dir,a,best,bestd;
	point_t t;
	for(i=0;i<n;i++) if(hix<p[i].x || (hix==p[i].x && loy>p[i].y)) hix=p[i].x,loy=p[i].y,ix=i;
	t=p[0],p[0]=p[ix],p[ix]=t;
	hn=ix=0;
	dir=pi/2;
	do {
		atx=p[ix].x; aty=p[ix].y;
		h[hn++]=p[ix];
		best=1e100; bestd=1e100;
		ix=-1;
		for(i=0;i<n;i++) if(p[i].x!=atx || p[i].y!=aty) {
			a=atan2(p[i].y-aty,p[i].x-atx);
			while(a+EPS<dir) a+=2*pi;
			if(fabs(best-a)<EPS && bestd>distsq(p[i].x,p[i].y,atx,aty)) best=a,ix=i,bestd=distsq(p[i].x,p[i].y,atx,aty);
			else if(fabs(best-a)>=EPS && best>a) best=a,bestd=distsq(p[i].x,p[i].y,atx,aty),ix=i;
		}
		if(ix<0) puts("error");
		dir=best;
	} while(ix);
}

int px[15],py[15];
int N;

void brute(int ix) {
	int mask,i,best=0;
	/* mask of trees to cut, 1:cut */
	for(mask=0;mask<(1<<N);mask++) if(!(mask&(1<<ix))) {
		for(n=i=0;i<N;i++) if(!(mask&(1<<i))) p[n].x=px[i],p[n++].y=py[i];
		if(best>=n) continue;
		if(n>3) {
			convexhull();
			for(i=0;i<hn;i++) if(h[i].x==px[ix] && h[i].y==py[ix]) {
				best=n;
				break;
			}
		} else best=n;
	}
	printf("%d\n",N-best);
}

void solve() {
	static int caseno=1;
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%d %d",&px[i],&py[i]);
	printf("Case #%d:\n",caseno++);
	for(i=0;i<N;i++) brute(i);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
