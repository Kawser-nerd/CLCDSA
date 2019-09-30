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
#define VAR(a,b) __typeof(b) a=b
#define FORIT(i,v) for(VAR(i,(v).begin());i!=(v).end();++i)
typedef long long ll; 

char buff[100];

int nr=0;
int been[10000000];
map<int,int> beenmap;

bool test(int x,int base) {
	++nr;
	beenmap.clear();
	while(x!=1) {
//		printf("%d %d\n",x,base);
		if(x<10000000) {
			if(been[x]==nr) return false; else been[x]=nr;
		} else {
			if(beenmap.count(x)) return false; else beenmap[x]=nr;
		}
		int y=0;
		while(x>0) { int z=x%base; x/=base; y+=z*z; }
//		printf("-> %d\n",y);
		x=y;
	}
	return true;
}

int go(vector<int> bases) {
	for(int ret=2;;++ret) {
		bool ok=true;
		REPSZ(i,bases) if(!test(ret,bases[i])) { ok=false; break; }
		if(ok) return ret;
	}
}

void testall() {
	vector<int> allbases; FORE(i,2,10) allbases.PB(i);
	REP(i,1<<SZ(allbases)) {
		vector<int> bases; REPSZ(j,allbases) if(i&(1<<j)) bases.PB(allbases[j]);
		int cur=go(bases);
		REPSZ(j,bases) printf("%d ",bases[j]); printf("= %d\n",cur);
	}
}

int main() {
	int nrcases; gets(buff); sscanf(buff,"%d",&nrcases);
//	testall();
	FORE(casenr,1,nrcases) {
		gets(buff);
		vector<int> bases;
		istringstream iss(buff); int base; while(iss>>base) bases.PB(base);
		int ret=go(bases);
		printf("Case #%d: %d\n",casenr,ret);
		fprintf(stderr,"Case #%d: %d\n",casenr,ret);
	}
	return 0;
}
