#include<cstdio>
#include<map>
#include<string>
#include<vector>
using namespace std;

#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define REPSZ(i,v) REP(i,SZ(v))

int turnaround;
int na,nb;
vector<int> froma,tob;
vector<int> fromb,toa;

int readtime() {
	int h,m; scanf("%d:%d",&h,&m);
	return h*60+m;
}

int calc(vector<int> from,vector<int> to) {
	sort(from.begin(),from.end());
	sort(to.begin(),to.end());
	int ret=0;
	int j=0;
	REPSZ(i,from) if(j<SZ(to)&&to[j]+turnaround<=from[i]) ++j; else ++ret;
	return ret;
}

void run(int casenr) {
	scanf("%d%d%d",&turnaround,&na,&nb);
	froma=tob=vector<int>(na);
	REP(i,na) { froma[i]=readtime(); tob[i]=readtime(); }
	fromb=toa=vector<int>(nb);
	REP(i,nb) { fromb[i]=readtime(); toa[i]=readtime(); }
	
	int reta=calc(froma,toa);
	int retb=calc(fromb,tob);
	printf("Case #%d: %d %d\n",casenr,reta,retb);
}

int main() {
	int n; scanf("%d",&n);
	FORE(i,1,n) run(i);
	return 0;
}
