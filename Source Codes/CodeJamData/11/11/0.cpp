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
	ll n; int pd,pg; scanf("%lld%d%d",&n,&pd,&pg);
	int d=1; while(pd*d%100!=0) ++d;
	printf("Case #%d: %s\n",casenr,d>n||pg==0&&pd>0||pg==100&&pd<100?"Broken":"Possible");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}

 
