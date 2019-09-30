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

const int MAXH=50;
const int MAXW=50;
const int MAXN=100;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w;
char g[MAXH][MAXW+1];

int n;
int id[MAXH][MAXW];

vector<int> opt[MAXH][MAXW],invalid;

bool go(int x,int y,int k,int cid,bool add) {
	while(true) {
		//printf("going %d: (%d,%d,%d)\n",cid,x,y,k);
		x+=DX[k],y+=DY[k];
		if(x<0||x>=h||y<0||y>=w||g[x][y]=='#') return true;
		if(g[x][y]=='.') { if(add) opt[x][y].PB(cid); continue; }
		if(g[x][y]=='/') { k^=1; continue; }
		if(g[x][y]=='\\') { k=3-k; continue; }
		return false;
	}
}

bool reach[2*MAXN][2*MAXN];
int ans[MAXN];
char ret[MAXH][MAXW+1];


bool solve() {
	REP(x,h) REP(y,w) id[x][y]=-1; n=0; REP(x,h) REP(y,w) if(g[x][y]=='-'||g[x][y]=='|') id[x][y]=n++;

	REP(x,h) REP(y,w) opt[x][y].clear(); invalid.clear();
	REP(x,h) REP(y,w) if(id[x][y]!=-1) {
		if(!go(x,y,0,2*id[x][y]+0,false)||!go(x,y,2,2*id[x][y]+0,false)) invalid.PB(2*id[x][y]+0); else go(x,y,0,2*id[x][y]+0,true),go(x,y,2,2*id[x][y]+0,true);
		if(!go(x,y,1,2*id[x][y]+1,false)||!go(x,y,3,2*id[x][y]+1,false)) invalid.PB(2*id[x][y]+1); else go(x,y,1,2*id[x][y]+1,true),go(x,y,3,2*id[x][y]+1,true);
	}

	REP(i,2*n) REP(j,2*n) reach[i][j]=i==j?true:false;
	REPSZ(i,invalid) { int z=invalid[i]; reach[z][z^1]=true; }
	REP(x,h) REP(y,w) if(g[x][y]=='.') {
		sort(opt[x][y].begin(),opt[x][y].end()); 
		opt[x][y].erase(unique(opt[x][y].begin(),opt[x][y].end()),opt[x][y].end());
		assert(SZ(opt[x][y])<=2);
		if(SZ(opt[x][y])==0) return false;
		if(SZ(opt[x][y])==1) { int z=opt[x][y][0]; reach[z^1][z]=true; }
		if(SZ(opt[x][y])==2) { int z1=opt[x][y][0],z2=opt[x][y][1]; reach[z1^1][z2]=reach[z2^1][z1]=true; }
	}
	//REP(i,2*n) { REP(j,2*n) printf("%c",reach[i][j]?'V':'.'); puts(""); }
	REP(k,2*n) REP(i,2*n) REP(j,2*n) if(reach[i][k]&&reach[k][j]) reach[i][j]=true;
	REP(i,n) if(reach[2*i+0][2*i+1]&&reach[2*i+1][2*i+0]) return false;

	REP(i,n) ans[i]=-1;
	while(true) {
		int cur=-1;
		REP(i,2*n) if(ans[i>>1]==-1) {
			bool ok=true;
			REP(j,2*n) if(ans[j>>1]==-1&&reach[i][j]&&!reach[j][i]) { ok=false; break; }
			if(ok) { cur=i; break; }
		}
		if(cur==-1) break;
		REP(i,2*n) if(ans[i>>1]==-1&&reach[cur][i]) ans[i>>1]=i%2;
	}
	REP(i,n) assert(ans[i]!=-1);
	REP(i,2*n) REP(j,2*n) if(reach[i][j]&&ans[i>>1]==i%2) assert(ans[j>>1]==j%2);

	REP(x,h) {
		REP(y,w) {
			if(id[x][y]==-1) { ret[x][y]=g[x][y]; continue; }
			int cur=id[x][y];
			ret[x][y]=ans[cur]==0?'|':'-';
		}
		ret[x][w]='\0';
	}
	return true;
}

void run(int casenr) {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);

	if(!solve()) { printf("Case #%d: IMPOSSIBLE\n",casenr); return; }
	printf("Case #%d: POSSIBLE\n",casenr);
	REP(x,h) printf("%s\n",ret[x]);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
