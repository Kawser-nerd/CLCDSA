#include <algorithm> 
#include <cassert>
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

const int MOD=1000000009;

int n,k;
vector<int> childs[500];

ll calc(int n,int x) {
	if(x>n) return 0;
	ll ret=1; REP(i,x) ret=ret*(n-i)%MOD; return ret;
}

ll go(int at,int prev,int no) {
	ll ret=calc(k-no,SZ(childs[at])-(prev!=-1?1:0));
	REPSZ(i,childs[at]) if(childs[at][i]!=prev) {
		ret=ret*go(childs[at][i],at,SZ(childs[at]))%MOD;
	}
	return ret;
}

void run(int casenr) {
	scanf("%d%d",&n,&k);
	REP(i,n) childs[i].clear();
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; childs[a].PB(b); childs[b].PB(a); }
	ll ret=go(0,-1,0);
	printf("Case #%d: %lld\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
