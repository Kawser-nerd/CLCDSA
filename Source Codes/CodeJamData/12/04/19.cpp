#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long s64;
typedef unsigned long long u64;


#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#define _Dm(fmt) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__)
#define _D(fmt, ...) fprintf(stderr, "%s %d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);
#define SIGN(n) (n==0?0:(n>0 ? 1 : -1))
#define ABS(n) ((n)<0?(-(n)):(n))

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int H,W,D;
char maps[40][40];
int gcm[51][51];
int mx,my;

int check(int dx,int dy) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei,stx,sty;
	double br,tb1,tb2,start,end;
	int smx,smy,lmx,lmy,lcm,ld,crx,cry,dist,disx,disy,sgx,sgy,step;
	int odx=dx,ody=dy;
	lcm=ABS(2*dx*dy);
	smx = lmx=mx*lcm + lcm/2;
	smy = lmy=my*lcm + lcm/2;
	dist = 0;
	ld=D*lcm;
	
	
	//_P("********lm(%d,%d) d(%d,%d) %d\n",lmx,lmy,dx,dy,lcm);
	//if(odx==3 && ody==-1) _P("s lm(%d,%d) d(%d,%d) st(%d,%d) step:%d %d %d\n",lmx,lmy,dx,dy,stx,sty,step,lcm,stx);
	step=0;
	crx=mx;cry=my;
	while((step*step)*(s64)(dx*(s64)dx+dy*dy) <= ld*(s64)ld) {
		assert(ABS(lmx%lcm)%ABS(dx)==0);
		assert(ABS(lmy%lcm)%ABS(dy)==0);
		
		assert(crx>0 && cry>0 && crx<W && cry<H);
		
		//if(odx==3 && ody==-1) _P("s lm(%d,%d) d(%d,%d) st(%d,%d) step:%d %d %d\n",lmx,lmy,dx,dy,stx,sty,step,lcm,stx);
		if(crx==mx && cry==my && step>0) {
			assert(ABS(smx-lmx)%ABS(dx)==0);
			assert(ABS(smy-lmy)%ABS(dy)==0);
			//if(odx==3 && ody==-1) _P("CHK s(%d,%d) l(%d,%d) d(%d,%d) step(%d,%d)\n",smx,smy,lmx,lmy,dx,dy,(smx-lmx)/dx,(smy-lmy)/dy);
			//if(odx==3 && ody==-1) _P("%d %d %d %d\n",crx,cry,W,H);
			if((smx-lmx)/dx == (smy-lmy)/dy) {
				//if(odx==3 && ody==-1) _P("%d %d %d %d\n",step,ld,(int)((step*ABS((s64)dx)+ABS(smx-lmx))),
				//int((step*ABS((s64)dy)+ABS(smy-lmy))));
				if((step*ABS((s64)dx)+ABS(smx-lmx))*(step*ABS((s64)dx)+ABS(smx-lmx)) + 
				   (step*ABS((s64)dy)+ABS(smy-lmy))*(step*ABS((s64)dy)+ABS(smy-lmy)) <= ld*(s64)ld) {
					//_E("CR lm(%d,%d) d(%d,%d) st(%d,%d) %d %d %d\n",lmx,lmy,dx,dy,stx,sty,step,lcm,stx);
				   //_P("hit! %d %d %d\n",odx,ody,(smy-lmy)/dy);
				   return 1;
				}
			}
		}
		
		stx = ((dx>0)?(lcm-lmx%lcm):(((lmx%lcm)==0)?lcm :(((lmx%lcm)+lcm)%lcm)))/ABS(dx);
		sty = ((dy>0)?(lcm-lmy%lcm):(((lmy%lcm)==0)?lcm :(((lmy%lcm)+lcm)%lcm)))/ABS(dy);
		//if(odx==3 && ody==-1) _P("s lm(%d,%d) d(%d,%d) st(%d,%d) step:%d %d %d\n",lmx,lmy,dx,dy,stx,sty,step,lcm,stx);
		assert(stx>0 && sty>0);
		
		sgx=SIGN(dx);
		sgy=SIGN(dy);
		
		if(stx==sty) {
			//proceed stx;
			lmx+=sty*dx;
			lmy+=sty*dy;
			step+=sty;
			
			
			if(maps[cry+sgy][crx+sgx]=='#') {
				if(maps[cry][crx+sgx]=='#' && maps[cry+sgy][crx]!='#') {
					dx=-dx;
					cry+=sgy;
				}
				else if(maps[cry][crx+sgx]!='#' && maps[cry+sgy][crx]=='#') {
					dy=-dy;
					crx+=sgx;
				}
				else if(maps[cry][crx+sgx]=='#' && maps[cry+sgy][crx]=='#') {
					dx=-dx;
					dy=-dy;
				}
				else {
					//break;
					return 0;
				}
			}
			else {
				crx+=sgx;
				cry+=sgy;
			}
			//if(odx==3 && ody==-1) _P("xy lm(%d,%d) d(%d,%d) st(%d,%d) step:%d %d %d\n",lmx,lmy,dx,dy,stx,sty,step,lcm,stx);
			
		}
		else if(stx>sty) {
			
			//proceed sty;
			lmx+=sty*dx;
			lmy+=sty*dy;
			step+=sty;
			if(maps[cry+sgy][crx]=='#') {
				dy=-dy;
			}
			else {
				cry+=sgy;
			}
			//if(odx==3 && ody==-1) _P("y lm(%d,%d) d(%d,%d) st(%d,%d) step:%d %d %d\n",lmx,lmy,dx,dy,stx,sty,step,lcm,stx);
		}
		else{
			//proceed stx;
			lmx+=stx*dx;
			lmy+=stx*dy;
			step+=stx;
			if(maps[cry][crx+sgx]=='#') {
				dx=-dx;
			}
			else {
				crx+=sgx;
			}
			//if(odx==3 && ody==-1) _P("x lm(%d,%d) d(%d,%d) st(%d,%d) step:%d %d %d\n",lmx,lmy,dx,dy,stx,sty,step,lcm,stx);
		}
		
		
		
		
	}
	return 0;
	
}

void solve(int _loop) {
	int i,j,k,result,res,dir,ok,state,fstate,up,x,y,sp,dist1,dist2;
	int wid,hei;
	double br,tb1,tb2,start,end;
	int dx,dy;
	
	result = 0;
	ZERO(maps);
	GET3(&H,&W,&D);
	
	FOR(i,H) {
		GETs(maps[i]);
	}
	
	FOR(y,H) {
		FOR(x,W) {
			if(maps[y][x]=='X') {
				mx=x;my=y;
				maps[y][x]='.';
			}
		}
	}
	
	//left
	x = mx;
	while(x>=0) {
		if(maps[my][x]=='#') break;
		x--;
	}
	if(x>=0 && (mx-x)*2-1 <= D) result++;
	
	//right
	x = mx;
	while(x<W) {
		if(maps[my][x]=='#') break;
		x++;
	}
	if(x<W && (x-mx)*2-1 <= D) result++;
	
	//up
	y = my;
	while(y>=0) {
		if(maps[y][mx]=='#') break;
		y--;
	}
	if(y>=0 && (my-y)*2-1 <= D) result++;
	
	//down
	y = my;
	while(y<H) {
		if(maps[y][mx]=='#') break;
		y++;
	}
	if(y<H && (y-my)*2-1 <= D) result++;
	
	for(dx=1;dx<=50;dx++) {
		for(dy=1;dy<=50;dy++) {
			if(gcm[dx][dy]>1) continue;
			if(dx*dx+dy*dy>D*D) continue;
			result += check(dx,dy);
			result += check(dx,-dy);
			result += check(-dx,dy);
			result += check(-dx,-dy);
		}
	}
	
	
	_PE("Case #%d: %d\n",_loop,result);
}

void init() {
	int i,j,k;
	
	ZERO(gcm);
	for(i=1;i<=50;i++) {
		for(j=i;j<=50;j++) {
			gcm[i][j]=gcm[j][i]=1;
			for(k=j;k>=2;k--) {
				if((i%k)==0 && (j%k)==0){
					gcm[i][j]=gcm[j][i]=k;
					break;
				}
			}
		}
	}
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) {
		freopen(argv[1], "r", stdin);
	}
	
	gettimeofday(&ts,NULL);
	
	GET1(&loops);
	gets(tmpline);
	init();
	
	if(loops>1000) {
		_E("loops is over 1000\n");
		return 0;
	}
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL);
		solve(loop);
		gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		_E("                                     time: %lld ms\n",span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	_E("**Total time: %lld ms\n",span/1000);
	
	return 0;
	
}



