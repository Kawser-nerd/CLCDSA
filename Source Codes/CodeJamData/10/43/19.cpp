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

typedef struct R { int x1,y1,x2,y2; } R;

const int DX[]={-1,-1,0,+1,+1,0},DY[]={0,+1,+1,0,-1,-1};
bool adj(R &a,R &b) {
	if(!(a.x2<b.x1||b.x2<a.x1)&&!(a.y2<b.y1||b.y2<a.y1)) return true; //overlap
	REP(k,6) if(!(a.x2+DX[k]<b.x1||b.x2<a.x1+DX[k])&&!(a.y2+DY[k]<b.y1||b.y2<a.y1+DY[k])) return true; //overlap after step
	return false;
}

void run(int casenr) {
	int nrect; scanf("%d",&nrect);
	vector<R> rect;
	REP(i,nrect) { int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2); rect.PB((R){x1,y1,x2,y2}); }
	vector<bool> done(nrect,false);
	int ret=0;
	REP(i,nrect) if(!done[i]) {
		queue<int> q; q.push(i); done[i]=true;
		int maxx=0,maxy=0,minxy=INT_MAX;
		while(!q.empty()) {
			int at=q.front(); q.pop();
//			printf("\t%d\n",at);
			maxx>?=rect[at].x2; maxy>?=rect[at].y2; minxy<?=rect[at].x1+rect[at].y1;
			REP(to,nrect) if(!done[to]&&adj(rect[at],rect[to])) {
				q.push(to); done[to]=true;
			}
		}
//		printf("=> %d %d %d\n",minxy,maxx,maxy);
		ret>?=maxx+maxy-minxy+1;
	}
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}

