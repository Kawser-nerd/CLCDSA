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

const int MAXCUST=1000;
const int MAXSEAT=1000;

int nseat,ncust,nsold;
int cnt[MAXCUST];
int need[MAXSEAT];

void run(int casenr) {
	scanf("%d%d%d",&nseat,&ncust,&nsold);
	REP(i,ncust) cnt[i]=0;
	REP(i,nseat) need[i]=0;
	REP(i,nsold) {
		int pos,by; scanf("%d%d",&pos,&by); --pos,--by;
		++cnt[by]; ++need[pos];
	}

	int sum=0;
	int ret=0;
	REP(i,nseat) {
		sum+=need[i];
		ret=max(ret,(sum+i)/(i+1));
	}
	REP(i,ncust) ret=max(ret,cnt[i]);
	
	int prom=0;
	REP(i,nseat) {
		if(need[i]>ret) prom+=need[i]-ret;
	}

	printf("Case #%d: %d %d\n",casenr,ret,prom);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
