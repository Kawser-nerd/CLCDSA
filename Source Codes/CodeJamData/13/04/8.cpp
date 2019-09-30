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

int nstartkeys,nchests;
vector<int> startkeys;
vector<int> needtype;
vector<vector<int> > gettype;

int ntypes;
vector<int> curtypes;
vector<bool> done;

int nkeys;
vector<pair<int,int> > keys;
vector<vector<int> > getind;
vector<vector<int> > adj;
vector<int> opens;
vector<int> openedby;


bool go() {
//	printf("done:"); REP(i,nchests) if(done[i]) printf(" %d",i); printf(" have:"); REP(i,ntypes) if(curtypes[i]>0) printf(" %d*%d",curtypes[i],i); puts("");

	getind=vector<vector<int> >(nchests);
	keys.clear();
	REP(i,ntypes) REP(j,curtypes[i]) keys.PB(MP(-1,i));
	REP(i,nchests) if(!done[i]) REPSZ(j,gettype[i]) { keys.PB(MP(i,gettype[i][j])); getind[i].PB(SZ(keys)-1); }
	nkeys=SZ(keys);
	opens=vector<int>(nkeys,-1);
	openedby=vector<int>(nchests,-1);
	adj=vector<vector<int> >(nkeys); REP(i,nkeys) REP(j,nkeys) if(keys[j].first!=-1&&keys[i].second==needtype[keys[j].first]) adj[i].PB(j);

	// wijs aan elke kist een sleutel toe
	vector<int> first(ntypes,-1);
	vector<int> next(nkeys,-1);
	REP(i,nkeys) { next[i]=first[keys[i].second]; first[keys[i].second]=i; }
	REP(i,nchests) if(!done[i]) {
		int cur=first[needtype[i]];
		if(cur==-1) return false;
		openedby[i]=cur;
		opens[cur]=i;
		first[needtype[i]]=next[cur];
	}

//	REP(i,nkeys) printf("key %d: (%d,%d)\n",i,keys[i].first,keys[i].second);
	// zolang er een cycle is:
	while(true) {
//		REP(i,nchests) if(openedby[i]!=-1) printf("%d opened by %d (%d,%d)\n",i,openedby[i],keys[openedby[i]].first,keys[openedby[i]].second); puts("");

		// bepaal source
		vector<int> state(nkeys,-1); vector<int> prev(nkeys,-1); queue<int> q;
		REP(i,nkeys) if(keys[i].first==-1) { state[i]=2; q.push(i); }
		while(!q.empty()) {
			int at=q.front(); q.pop();
//			printf("\tat=%d\n",at);
			if(opens[at]==-1) continue;
			REPSZ(i,getind[opens[at]]) { int to=getind[opens[at]][i]; state[to]=2; q.push(to); }
		}
		bool done=true; REP(i,nkeys) if(state[i]!=2) done=false; if(done) return true;

		// bepaal cycles
		REP(i,nkeys) if(state[i]==-1) {
			int at=i;
			while(state[at]==-1) {
				state[at]=3;
				at=openedby[keys[at].first];
			}
			while(state[at]==3) {
				state[at]=1;
				at=openedby[keys[at].first];
			}
			at=i;
			while(state[at]==3) {
				state[at]=0;
				at=openedby[keys[at].first];
			}
		}
		
		// zoek pad vanuit source naar element in cycle
		int dest=-1;
		REP(i,nkeys) if(state[i]==2) q.push(i);
		while(!q.empty()) {
			int at=q.front(); q.pop();
			if(state[at]==1) { dest=at; break; }
			REPSZ(i,adj[at]) {
				int to=adj[at][i];
				if(state[to]==2||prev[to]!=-1) continue;
				prev[to]=at; q.push(to);
			}
		}
		if(dest==-1) return false;

		// pas toewijzing aan
		for(int x=dest;state[x]!=2;x=prev[x]) {
			int nchest=keys[x].first,nkey=prev[x];
			int pchest=opens[prev[x]],pkey=openedby[keys[x].first];
//			printf("(%d opens %d) and (%d opens %d) switch\n",pkey,nchest,nkey,pchest);
			opens[nkey]=nchest; if(nchest!=-1) openedby[nchest]=nkey;
			opens[pkey]=pchest; if(pchest!=-1) openedby[pchest]=pkey;
		}
	}
}

void run(int casenr) {
	scanf("%d%d",&nstartkeys,&nchests);
	startkeys.clear(); REP(i,nstartkeys) { int x; scanf("%d",&x); startkeys.PB(x); }
	needtype=vector<int>(nchests); gettype=vector<vector<int> >(nchests);
	REP(i,nchests) { int cnt; scanf("%d%d",&needtype[i],&cnt); REP(j,cnt) { int x; scanf("%d",&x); gettype[i].PB(x); } }

	vector<int> alltypes; REPSZ(i,startkeys) alltypes.PB(startkeys[i]); REP(i,nchests) alltypes.PB(needtype[i]); REP(i,nchests) REPSZ(j,gettype[i]) alltypes.PB(gettype[i][j]);
	sort(alltypes.begin(),alltypes.end()); alltypes.erase(unique(alltypes.begin(),alltypes.end()),alltypes.end()); map<int,int> typemap; REPSZ(i,alltypes) typemap[alltypes[i]]=i;
	REPSZ(i,startkeys) startkeys[i]=typemap[startkeys[i]]; REP(i,nchests) needtype[i]=typemap[needtype[i]]; REP(i,nchests) REPSZ(j,gettype[i]) gettype[i][j]=typemap[gettype[i][j]];



	ntypes=SZ(alltypes);
	curtypes=vector<int>(ntypes,0);
	REPSZ(i,startkeys) curtypes[startkeys[i]]++;

	vector<int> path;
	done=vector<bool>(nchests,false);
	while(SZ(path)!=nchests) {
		bool found=false;
		REP(at,nchests) if(!done[at]&&curtypes[needtype[at]]>0) {
			REPSZ(i,gettype[at]) ++curtypes[gettype[at][i]]; --curtypes[needtype[at]]; done[at]=true;
			if(go()) {
				found=true;
				path.PB(at);
				break;
			}
			REPSZ(i,gettype[at]) --curtypes[gettype[at][i]]; ++curtypes[needtype[at]]; done[at]=false;
		}
		if(!found) break;
	}
	if(SZ(path)!=nchests) {
		printf("Case #%d: IMPOSSIBLE\n",casenr);
	} else {
		printf("Case #%d:",casenr); REPSZ(i,path) printf(" %d",path[i]+1); puts("");
	}
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}