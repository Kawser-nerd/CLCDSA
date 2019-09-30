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

int g[100][100];

void run(int casenr) {
	int R,C; scanf("%d%d",&R,&C);
	REP(r,R) REP(c,C) scanf("%d",&g[r][c]);

	vector<int> mowr(R,0),mowc(C,0);
	REP(r,R) REP(c,C) {
		if(g[r][c]>mowr[r]) mowr[r]=g[r][c];
		if(g[r][c]>mowc[c]) mowc[c]=g[r][c];
	}
	
	bool ok=true;
	REP(r,R) REP(c,C) if(min(mowr[r],mowc[c])!=g[r][c]) ok=false;
	printf("Case #%d: %s\n",casenr,ok?"YES":"NO");
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
