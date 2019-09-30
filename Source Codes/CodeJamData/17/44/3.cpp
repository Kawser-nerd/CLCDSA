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
#include <climits>
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

const int MAXH=100;
const int MAXW=100;
const int MAXS=100;
const int MAXT=100;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};


int h,w,dmx;
char g[MAXH][MAXW+1];

int sid[MAXH][MAXW],ns;
int tid[MAXH][MAXW],nt;

bool cansee[MAXH][MAXW][MAXT];
int dist[MAXS][MAXT];

int qx[MAXH*MAXW],qy[MAXH*MAXW],qhead,qtail;
int d[MAXH][MAXW];
int px[MAXH][MAXW],py[MAXH][MAXW];

int shotby[MAXT];
int shoots[MAXS];
bool been[MAXS];
bool augment(int s) {
	if(been[s]) return false; else been[s]=true;
	REP(t,nt) if(dist[s][t]<=dmx&&(shotby[t]==-1||augment(shotby[t]))) {
		shotby[t]=s; shoots[s]=t; return true;
	}
	return false;
}

bool dead[MAXT];
bool done[MAXS];
int cx[MAXS],cy[MAXS];
int ret[MAXS][2],nret;
vector<pair<int,int> > path[MAXS];
int waitfor[MAXS];

vector<pair<int,int> > calcpath(int s,int t) {
	//printf("%d to %d\n",s,t);
	qhead=qtail=0; REP(x,h) REP(y,w) d[x][y]=INT_MAX; d[cx[s]][cy[s]]=0,qx[qhead]=cx[s],qy[qhead]=cy[s],++qhead;
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail]; ++qtail;
		//printf("%d %d\n",x,y);
		if(cansee[x][y][t]) {
			vector<pair<int,int> > ret;
			while(x!=cx[s]||y!=cy[s]) {
				ret.PB(MP(x,y));
				int nx=px[x][y],ny=py[x][y]; x=nx,y=ny;
			}
			return ret;
		}
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='#'||d[nx][ny]!=INT_MAX) continue;
			d[nx][ny]=d[x][y]+1,qx[qhead]=nx,qy[qhead]=ny,++qhead; px[nx][ny]=x,py[nx][ny]=y;
		}
	}
	assert(false);
}

void run(int casenr) {
	scanf("%d%d%d",&w,&h,&dmx);
	REP(x,h) scanf("%s",g[x]);

	ns=0; REP(x,h) REP(y,w) if(g[x][y]=='S') sid[x][y]=ns++;
	nt=0; REP(x,h) REP(y,w) if(g[x][y]=='T') tid[x][y]=nt++;
	REP(x,h) REP(y,w) REP(t,nt) cansee[x][y][t]=false;
	REP(x,h) REP(y,w) if(g[x][y]=='T') REP(k,4) {
		int nx=x+DX[k],ny=y+DY[k];
		while(0<=nx&&nx<h&&0<=ny&&ny<w&&g[nx][ny]!='#') {
			cansee[nx][ny][tid[x][y]]=true;
			nx+=DX[k],ny+=DY[k];
		}
	}
	REP(sx,h) REP(sy,w) if(g[sx][sy]=='S') {
		REP(t,nt) dist[sid[sx][sy]][t]=INT_MAX;
		qhead=qtail=0; REP(x,h) REP(y,w) d[x][y]=INT_MAX; d[sx][sy]=0,qx[qhead]=sx,qy[qhead]=sy,++qhead;
		while(qtail<qhead) {
			int x=qx[qtail],y=qy[qtail]; ++qtail;
			REP(t,nt) if(cansee[x][y][t]&&d[x][y]<dist[sid[sx][sy]][t]) { dist[sid[sx][sy]][t]=d[x][y]; /*printf("%d sees %d from (%d,%d) at dist %d\n",sid[sx][sy],t,x,y,d[x][y]);*/ }
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='#'||d[nx][ny]!=INT_MAX) continue;
				d[nx][ny]=d[x][y]+1,qx[qhead]=nx,qy[qhead]=ny,++qhead;
			}
		}
	}
	//REP(s,ns) { REP(t,nt) printf("%2d ",dist[s][t]==INT_MAX?-1:dist[s][t]); puts(""); } puts("");

	int expect=0;
	REP(t,nt) shotby[t]=-1; REP(s,ns) shoots[s]=-1;
	REP(i,ns) {
		REP(ss,ns) been[ss]=false;
		if(augment(i)) ++expect;
	}
	//printf("expect=%d\n",expect);

	REP(s,ns) done[s]=shoots[s]==-1; REP(t,nt) dead[t]=false; nret=0;
	REP(x,h) REP(y,w) if(g[x][y]=='S') cx[sid[x][y]]=x,cy[sid[x][y]]=y;
	REP(s,ns) if(!done[s]) path[s]=calcpath(s,shoots[s]);
	while(true) {
		//printf("iter\n");
		bool change=false;
		REP(s,ns) waitfor[s]=-1;
		REP(s,ns) if(!done[s]) {
			while(SZ(path[s])>0) {
				int x=cx[s],y=cy[s]; int stoppedby=-1; //printf("%d: (%d,%d)\n",s,x,y);
				REP(t,nt) if(!dead[t]&&cansee[x][y][t]) { stoppedby=t; break; }
				if(stoppedby==-1) { cx[s]=path[s].back().first; cy[s]=path[s].back().second; path[s].pop_back(); continue; }
				if(shotby[stoppedby]==-1) { shotby[shoots[s]]=-1; shotby[stoppedby]=s; shoots[s]=stoppedby; done[s]=true; dead[stoppedby]=true; ret[nret][0]=s,ret[nret][1]=shoots[s],++nret; change=true; break; }
				waitfor[s]=shotby[stoppedby]; break;
			}
			if(SZ(path[s])==0&&!done[s]) {
				done[s]=true; dead[shoots[s]]=true; ret[nret][0]=s,ret[nret][1]=shoots[s],++nret; change=true;
			}
		}
		if(change) continue;
		//printf("cycle\n");
		REP(s,ns) if(!done[s]) {
			assert(waitfor[s]!=-1);
			REP(ss,ns) been[ss]=false;
			int cs=s; while(!been[cs]) { been[cs]=true; cs=waitfor[cs]; assert(cs!=-1&&!done[cs]&&waitfor[cs]!=-1); }
			//printf("ccs=%d\n",cs);
			while(been[cs]) { ret[nret][0]=cs,ret[nret][1]=shoots[waitfor[cs]],++nret; done[cs]=dead[shoots[waitfor[cs]]]=true; been[cs]=false; cs=waitfor[cs]; change=true; }
			break;
		}
		if(!change) break;
	}
	REP(s,ns) assert(done[s]);

	printf("Case #%d: %d\n",casenr,expect);
	REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
