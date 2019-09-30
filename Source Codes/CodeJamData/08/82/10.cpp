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

typedef struct X { int from,to,id; } X;
bool operator<(const X &a,const X &b) { return a.from<b.from; }


int n;
X x[300];
map<string,int> name2id;

void run(int casenr) {
	scanf("%d",&n);
	name2id.clear();
	REP(i,n) { char tmp[20]; scanf("%s%d%d",tmp,&x[i].from,&x[i].to); string s=tmp; if(!name2id.count(s)) name2id[s]=SZ(name2id)-1; x[i].id=name2id[s]; }
	sort(x,x+n);
	
//	REP(i,n) printf("%d: %d-%d\n",x[i].id,x[i].from,x[i].to);
	
	int m=SZ(name2id);
	int ret=INT_MAX;
	REP(a,m) FOR(b,a,m) FOR(c,b,m) {
		int at=1,to=0,cur=0; bool ok=true;
		REP(i,n) if(x[i].id==a||x[i].id==b||x[i].id==c) {
			if(x[i].from>at) {
//				printf("%d %d %d -> at=%d to=%d\n",a,b,c,at,to);
				if(to<x[i].from) { ok=false; break; }
				at=to; ++cur;
				if(cur>=ret) break;
			}
			to=max(to,x[i].to+1);
		}
		if(at<=10000)  { if(to<=10000) ok=false; else at=to,++cur; }
		if(!ok) continue;
//		printf("%d %d %d: %d\n",a,b,c,cur);
		ret=min(ret,cur);
	}
	if(ret==INT_MAX) printf("Case #%d: IMPOSSIBLE\n",casenr);
	else printf("Case #%d: %d\n",casenr,ret);
	fprintf(stderr,".");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
