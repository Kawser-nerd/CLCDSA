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
#define VAR(a,b) __typeof(b) a=b
#define FORIT(i,v) for(VAR(i,(v).begin());i!=(v).end();++i)
typedef long long ll; 

int h,w;

int ns[20][20],ew[20][20],offset[20][20];

ll best[40][40];
ll calc(ll t,ll offset,ll can,ll period) {
	offset-=((offset+period-1)/period+1)*period;
	// offset+?*period <= ! < offset+?*period+can , t <= !
	ll x=(t-offset-can)/period+1;
	assert(t<offset+x*period+can);
	assert(!(t<offset+(x-1)*period+can));
	ll ret=max(t,offset+x*period)+1;
//	printf("t=%lld (offset=%lld,period=%lld,can=%lld) -> %lld\n",t,offset,period,can,ret);
	return ret;
}

int main() {
	int nrcases; scanf("%d",&nrcases);
	FORE(casenr,1,nrcases) {
		scanf("%d%d",&h,&w);
		REP(i,h) REP(j,w) scanf("%d%d%d",&ns[i][j],&ew[i][j],&offset[i][j]);
		memset(best,-1,sizeof(best));
		priority_queue<pair<ll,pair<int,int> > > q;
		#define ADD(x,y,c) if(best[x][y]==-1||c<best[x][y]) best[x][y]=c,q.push(MP(-c,MP(x,y)));
		ADD(2*h-1,0,0);
		while(!q.empty()) {
			ll t=-q.top().first; int x=q.top().second.first,y=q.top().second.second; q.pop();
			if(best[x][y]<t) continue;
//			printf("%d %d = %lld\n",x,y,t);
			REP(k,4) {
				const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
				int nx=x+DX[k],ny=y+DY[k]; ll nt;
				if(nx<0||nx>=2*h||ny<0||ny>=2*w) continue;
				if(DX[k]!=0) {
					if(x/2!=nx/2) nt=t+2;
					else nt=calc(t,offset[x/2][y/2],ns[x/2][y/2],ns[x/2][y/2]+ew[x/2][y/2]);
				} else if(DY[k]!=0) {
					if(y/2!=ny/2) nt=t+2;
					else nt=calc(t,offset[x/2][y/2]+ns[x/2][y/2],ew[x/2][y/2],ns[x/2][y/2]+ew[x/2][y/2]);
				} else assert(false);
				ADD(nx,ny,nt);
			}
		}
		
		printf("Case #%d: %lld\n",casenr,best[0][2*w-1]);
	}
	return 0;
}
