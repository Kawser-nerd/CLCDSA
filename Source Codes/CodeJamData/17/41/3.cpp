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

const int MAXP=4;

int n,p;
int cnt[MAXP];

void run(int casenr) {
	scanf("%d%d",&n,&p); REP(i,p) cnt[i]=0; REP(i,n) { int x; scanf("%d",&x); ++cnt[x%p]; }
	int ret=0;
	ret+=cnt[0]; cnt[0]=0;
	FOR(i,1,p) {
		int j=p-i;
		if(i!=j) {
			int cur=min(cnt[i],cnt[j]);
			ret+=cur; cnt[i]-=cur; cnt[j]-=cur;
		} else {
			int cur=cnt[i]/2;
			ret+=cur; cnt[i]-=2*cur;
		}
	}
	int at=0;
	for(int i=p-1;i>=0;--i) while(cnt[i]>0) {
		if(at==0) ++ret; at=(at+i)%p; --cnt[i];
		if(at!=0&&cnt[p-at]!=0) --cnt[p-at],at=0;
	}
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
