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

void run(int casenr) {
	ll len; int n; scanf("%lld%d",&len,&n);
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	sort(x.rbegin(),x.rend());
	int large=x[0];
	x.erase(x.begin()+0);
	
	vector<int> best(large,INT_MAX);
	priority_queue<pair<int,int> > q;
	#define ADD(pos,val) if(val<best[pos]) { best[pos]=val; q.push(MP(-(val),pos)); }
	ADD(0,0);
	while(!q.empty()) {
		int cost=-q.top().first,at=q.top().second; q.pop();
		if(cost>best[at]) continue;
		REP(i,n) {
			int to=at+x[i],ncost=cost+1;
			if(to>=large) to-=large,--ncost;
			ADD(to,ncost);
		}
	}
	int mod=(int)(len%large);
	if(best[mod]==INT_MAX) printf("Case #%d: IMPOSSIBLE\n",casenr);
	else printf("Case #%d: %lld\n",casenr,best[mod]+(len-mod)/large);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}
