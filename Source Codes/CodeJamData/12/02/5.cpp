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
#include <cstring>
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
	int n,nsuprising,need; scanf("%d%d%d",&n,&nsuprising,&need);
	
	// a,a,a | a,a,a+1 | a,a,a+2* | a,a+1,a+1 | a,a+1,a+2* | a,a+2,a+2*
	int no=0,maybe=0,yes=0;
	REP(i,n) {
		int score; scanf("%d",&score);
		bool cannormal=false,cansuprising=false;
		REPE(a,2) FORE(b,a,2) {
			int shrt=a+b; if((score+shrt)%3!=0||(score+shrt)/3<need||(score+shrt)/3<b) continue;
			if(b<2) cannormal=true; else cansuprising=true;
		}
//		printf("%d -> %d %d\n",score,cannormal,cansuprising);
		if(cannormal&&!cansuprising) ++no;
		if(cannormal&&cansuprising) ++maybe;
		if(!cannormal&&cansuprising) ++yes;
	}
	int ret=no+maybe+min(nsuprising,yes);
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
