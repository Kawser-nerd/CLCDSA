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
#include <cassert>
#include <cstring>
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

typedef struct P { int x,y; P(int x,int y):x(x),y(y) {} } P;

P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
int operator^(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }

int sign(int x) { return x<0?-1:x>0?+1:0; }
int getside(const P &a,const P &b,const P &c) {
//	printf("\t\t(%d,%d)-(%d,%d)-(%d,%d)=%d\n",a.x,a.y,b.x,b.y,c.x,c.y,sign((b-a)^(c-a)));
	int ret=(b-a)^(c-a); return sign(ret);
}


int h,w,dist;
char g[30][30];

void run(int casenr) {
	scanf("%d%d%d",&h,&w,&dist);
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);
	int qx=-1,qy=-1; REP(x,h) REP(y,w) if(g[x][y]=='X') qx=x,qy=y;

	int ret=0;
	FORE(xx,-dist,+dist) FORE(yy,-dist,+dist) if(0<xx*xx+yy*yy&&xx*xx+yy*yy<=dist*dist) {
		int sx=qx,sy=qy,tx=sx+xx,ty=sy+yy,x=sx,y=sy,qqq=0; bool ok=true;
//		printf("dir (%d,%d)\n",xx,yy);
		while(x!=tx||y!=ty) {
//			if(++qqq>20) exit(0);
//			printf("\t(%d,%d)->(%d,%d): (%d,%d)\n",sx,sy,tx,ty,x,y);
			int nx,ny;
			int dx=sign(tx-sx),dy=sign(ty-sy);
			if(dx==0) { nx=x,ny=y+dy; }
			else if(dy==0) { ny=y,nx=x+dx; }
			else {
				int side=getside(P(2*sx,2*sy),P(2*x+dx,2*y+dy),P(2*tx,2*ty));
				int xside=getside(P(2*sx,2*sy),P(2*x+dx,2*y+dy),P(2*(x+dx),2*y));
				int yside=getside(P(2*sx,2*sy),P(2*x+dx,2*y+dy),P(2*x,2*(y+dy)));
//				printf("side=%d xside=%d yside=%d\n",side,xside,yside);
				if(side==0) { nx=x+dx,ny=y+dy; }
				else { assert(xside!=yside); if(side==xside) nx=x+dx,ny=y; else nx=x,ny=y+dy; }
			}
			if(g[nx][ny]=='#') {
				if(x==nx) {
					sy=2*y+dy-sy; ty=2*y+dy-ty;
				} else if(y==ny) {
					sx=2*x+dx-sx; tx=2*x+dx-tx;
				} else {
					bool xmir=g[x+dx][y]=='#',ymir=g[x][y+dy]=='#';
					if(!xmir&&!ymir) { ok=false; break; }
					if(xmir) { sx=2*x+dx-sx; tx=2*x+dx-tx; }
					if(ymir) { sy=2*y+dy-sy; ty=2*y+dy-ty; }
				}
			} else {
				x=nx,y=ny;
			}
			if(g[x][y]=='X'&&(x!=tx||y!=ty)&&getside(P(sx,sy),P(tx,ty),P(x,y))==0) { ok=false; break; }
		}
		if(ok&&tx==qx&&ty==qy) {
			++ret;
//			printf("dir (%d,%d) -> (%d,%d)\n",xx,yy,tx,ty);
		}
	}
	printf("Case #%d: %d\n",casenr,ret);
	
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
