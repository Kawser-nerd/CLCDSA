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

void run(int casenr) {
	int n; scanf("%d",&n);
	vector<int> start(n); REP(i,n) scanf("%d",&start[i]);
	vector<int> now(n); REP(i,n) now[i]=start[i];
	vector<double> end(n);
	int left=0; REP(i,n) left+=start[i]; int sum=left;
	while(left>0) {
		int low=INT_MAX; REP(i,n) if(now[i]<low) low=now[i];
		int cnt=0; REP(i,n) if(now[i]==low) ++cnt;
		int nextlow=INT_MAX; REP(i,n) if(now[i]>low&&now[i]<nextlow) nextlow=now[i];
//		printf("%d -> %d (%d)\n",low,nextlow,cnt);
		if(nextlow==INT_MAX) {
			double each=1.0*left/cnt;
			REP(i,n) end[i]=now[i]+each;
			left=0;
		} else {
			int need=(nextlow-low)*cnt;
			if(left>need) {
				REP(i,n) if(now[i]==low) now[i]=nextlow;
				left-=need;
			} else {
				double each=1.0*left/cnt;
				REP(i,n) end[i]=now[i]+(now[i]==low?each:0.0);
				left=0;
			}
		}
	}
//	REP(i,n) printf("%d -> %lf\n",start[i],end[i]);
	printf("Case #%d:",casenr); REP(i,n) printf(" %.6lf",100*(end[i]-start[i])/sum); puts("");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}

 
