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

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w,n;

int ways[5];
int calc(int z) {
	REP(i,5) ways[i]=0;
	REP(x,h) REP(y,w) {
		if((x+y)%2==z) { ++ways[0]; continue; }
		int cnt=0; REP(k,4) { int nx=x+DX[k],ny=y+DY[k]; if(0<=nx&&nx<h&&0<=ny&&ny<w) ++cnt; } ++ways[cnt];
	}
	int left=n,ret=0;
	REP(i,5) {
		int cur=min(left,ways[i]);
		left-=cur; ret+=i*cur;
	}
	return ret;
}

void run(int casenr) {
	scanf("%d%d%d",&h,&w,&n);
	printf("Case #%d: %d\n",casenr,min(calc(0),calc(1)));
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
