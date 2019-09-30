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
	int n; ll maxval; scanf("%d%lld",&n,&maxval);
	
	ll have=n; ll ret=n;
	while(have<n*maxval) {
		ll rhs=(have+n)/n;
		ll x=rhs;
		ll cnt=n-have/x;
		have+=cnt*x; ret+=cnt;
	}
	printf("Case #%d: %lld\n",casenr,ret);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}
