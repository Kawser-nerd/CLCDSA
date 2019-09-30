#include <cassert>
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <list> 
using namespace std; 

#define PB push_back 
#define MP make_pair 
#define SZ(v) ((int)(v).size()) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=(b);++i) 
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) REP(i,SZ(v)) 
typedef long long ll; 

const double eps=1e-9;

typedef struct P { double x,y; P(double x,double y):x(x),y(y) {} P() {} } P;
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
P operator*(const double &a,const P &b) { return P(a*b.x,a*b.y); }

typedef struct T { P p[3]; } T;

T t[2];

double A[2][3];

void gaussjord() {
//	REP(i,2) { REP(j,3) printf("%10.2lf",A[i][j]); puts(""); } puts("");
	int R=2,C=3;
	int r=0,c=0;
	while(r<R&&c<C) {
		int rr=r; while(rr<R&&fabs(A[rr][c])<eps) ++rr; if(rr>=R) { ++c; continue; }
		REP(j,C) swap(A[r][j],A[rr][j]);
		for(int j=C-1;j>=c;--j) A[r][j]/=A[r][c];
		FOR(i,r+1,R) for(int j=C-1;j>=c;--j) A[i][j]-=A[i][c]*A[r][j];
		++r,++c;
	}
	while(--r>=0) {
		c=0; while(c<C&&fabs(A[r][c])<eps) ++c; assert(c<C);
		REP(i,r) for(int j=C-1;j>=c;--j) A[i][j]-=A[i][c]*A[r][j];
	}
//	REP(i,2) { REP(j,3) printf("%10.2lf",A[i][j]); puts(""); } puts("");
}


void run(int casenr) {
	REP(i,2) REP(j,3) scanf("%lf%lf",&t[i].p[j].x,&t[i].p[j].y);
	P x[2],y[2];
	REP(i,2) {
		x[i]=t[i].p[1]-t[i].p[0];
		y[i].x=-x[i].y; y[i].y=x[i].x;
//		printf("%d: x = %lf / %lf\n",i,x[i].x,x[i].y);
//		printf("%d: y = %lf / %lf\n",i,y[i].x,y[i].y);
	}
	P dx=x[0]-x[1],dy=y[0]-y[1],dz=t[1].p[0]-t[0].p[0];
	A[0][0]=dx.x; A[1][0]=dx.y;
	A[0][1]=dy.x; A[1][1]=dy.y;
	A[0][2]=dz.x; A[1][2]=dz.y;
	gaussjord();
	double xx,yy; bool ok=true;
	if(fabs(A[0][0])<eps) {
		if(fabs(A[0][1])<eps) {
			if(fabs(A[0][2])>eps||fabs(A[1][2])>eps) {
				ok=false;
			} else {
				xx=0,yy=0;
			}
		} else {
			assert(fabs(A[1][1]-1)<eps);
			if(fabs(A[1][2])>eps) {
				ok=false;
			} else {
				xx=0,yy=A[0][2];
			}
		}
	} else {
		assert(fabs(A[0][0]-1)<eps);
		if(fabs(A[1][1])<eps) {
			if(fabs(A[1][2])>eps) {
				ok=false;
			} else {
				xx=A[0][2],yy=0;
			}
		} else {
			assert(fabs(A[1][1]-1)<eps);
			xx=A[0][2],yy=A[1][2];
		}
	}
	
	if(ok) {
		P r=t[0].p[0]+xx*x[0]+yy*y[0];
		printf("Case #%d: %.9lf %.9lf\n",casenr,r.x,r.y);
	} else {
		printf("Case #1: No Solution\n",casenr);
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
