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

char g[4][4];

void run(int casenr) {
	REP(i,4) REP(j,4) scanf(" %c",&g[i][j]);

	vector<vector<pair<int,int> > > lines;
	REP(i,4) { vector<pair<int,int> > line; REP(j,4) line.PB(MP(i,j)); lines.PB(line); }
	REP(i,4) { vector<pair<int,int> > line; REP(j,4) line.PB(MP(j,i)); lines.PB(line); }
	{ vector<pair<int,int> > line; REP(i,4) line.PB(MP(i,i)); lines.PB(line); }
	{ vector<pair<int,int> > line; REP(i,4) line.PB(MP(i,3-i)); lines.PB(line); }
//	REPSZ(i,lines) { REPSZ(j,lines[i]) printf("(%d,%d)",lines[i][j].first,lines[i][j].second); puts(""); }

	bool xwon=false,owon=false,draw=true;
	REP(i,4) REP(j,4) if(g[i][j]=='.') draw=false;
	REPSZ(i,lines) {
		int cntx=0,cnto=0,cntt=0;
		REPSZ(j,lines[i]) { char c=g[lines[i][j].first][lines[i][j].second]; if(c=='X') ++cntx; else if(c=='O') ++cnto; else if(c=='T') ++cntt; }
		if(cntx==4||cntx==3&&cntt==1) xwon=true;
		if(cnto==4||cnto==3&&cntt==1) owon=true;
	}

	if(xwon) printf("Case #%d: X won\n",casenr);
	else if(owon) printf("Case #%d: O won\n",casenr);
	else if(draw) printf("Case #%d: Draw\n",casenr);
	else printf("Case #%d: Game has not completed\n",casenr);
}


int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
