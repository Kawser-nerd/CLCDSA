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
	int a,b; scanf("%d%d",&a,&b);
	ll ret=0;
	FORE(n,a,b) {
		int ndig=1,maxpower=1,curpower=10;
		for(int x=n/10;x>0;x/=10) ++ndig,maxpower*=10;
		vector<int> cur;
		FOR(i,1,ndig) {
			int m=(n%curpower)*(maxpower/curpower*10)+(n/curpower);
//			printf("%d shift %d = %d (%d+%d)\n",n,i,m,(n%curpower)*(maxpower/curpower),(n/curpower));
			if(a<=m&&m<n&&n<=b) cur.PB(m);
			curpower*=10;
		}
		sort(cur.begin(),cur.end()); cur.erase(unique(cur.begin(),cur.end()),cur.end());
		ret+=SZ(cur);
	}
	
	printf("Case #%d: %lld\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
