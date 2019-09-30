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

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

typedef struct Q { int t; int x,y; Q(int t,int x,int y):t(t),x(x),y(y) {} } Q;
bool operator<(const Q &a,const Q &b) { return a.t>b.t; }

void run(int casenr) {
	int sz,h,w; scanf("%d%d%d",&sz,&h,&w);
	vector<vector<int> > ceil(h,vector<int>(w)); REP(x,h) REP(y,w) scanf("%d",&ceil[x][y]);
	vector<vector<int> > floor(h,vector<int>(w)); REP(x,h) REP(y,w) scanf("%d",&floor[x][y]);

	vector<vector<int> > best(h,vector<int>(w,INT_MAX)); best[0][0]=0;
	priority_queue<Q> q; q.push(Q(0,0,0));
	while(!q.empty()) {
		int t=q.top().t; int x=q.top().x,y=q.top().y; q.pop();
		if(t>best[x][y]) continue;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w) continue;
			if(ceil[nx][ny]-floor[nx][ny]<50) continue;
			if(ceil[x][y]-floor[nx][ny]<50) continue;
			if(ceil[nx][ny]-floor[x][y]<50) continue;
			int wt=sz-ceil[nx][ny]+50; // sz-10*wt<=ceil[nx][ny]-50 -> wt>=(sz-ceil[nx][ny]+50)/10
			int nt=max(t,wt);
			if(nt!=0) nt+=sz-nt>=floor[x][y]+20?10:100;
			if(nt<best[nx][ny]) { best[nx][ny]=nt; q.push(Q(nt,nx,ny)); }
		}
	}
	assert(best[h-1][w-1]!=INT_MAX);
	printf("Case #%d: %.1lf\n",casenr,0.1*best[h-1][w-1]);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}

 
