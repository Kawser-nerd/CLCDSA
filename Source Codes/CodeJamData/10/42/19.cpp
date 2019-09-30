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

int P,n;
vector<int> a;

typedef struct M { int a,b,c,need; } M;
vector<M> matches;

int mem[1<<10][11];
int go(int at,int have) {
	if(at==-1) return 0;
	assert(at<(1<<10));
	assert(have<11);
	int &ret=mem[at][have];
	if(ret==-1) {
		ret=INT_MAX;
		REP(buy,2) {
			if(have+buy<matches[at].need) continue;
			int a=go(matches[at].a,have+buy);
			int b=go(matches[at].b,have+buy);
			if(a==INT_MAX||b==INT_MAX) continue;
			int cur=a+b+(buy==0?0:matches[at].c);
			ret<?=cur;
		}
//		printf("%d %d = %d\n",at,have,ret);
	}
	return ret;	
}


void run(int casenr) {
	scanf("%d",&P); n=1<<P;
	a=vector<int>(n); REP(i,n) scanf("%d",&a[i]);
	vector<int> first(P);
	matches.clear();
	REP(i,P) {
		first[i]=SZ(matches);
		REP(j,1<<(P-i-1)) {
			int cost; scanf("%d",&cost);
			if(i==0) {
				matches.PB((M){-1,-1,cost,P-min(a[2*j+0],a[2*j+1])});
			} else {
				matches.PB((M){first[i-1]+2*j,first[i-1]+2*j+1,cost,0});
			}
		}
	}
//	REPSZ(i,matches) printf("%d: prev=%d/%d cost=%d need=%d\n",i,matches[i].a,matches[i].b,matches[i].c,matches[i].need);
	memset(mem,-1,sizeof(mem));
	int ret=go(SZ(matches)-1,0);
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}

