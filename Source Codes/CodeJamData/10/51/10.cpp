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
typedef long long ll; 

int calc(int a,const vector<int> &x,int p,int &res) {
	if(SZ(x)<2) return 2;
	if(x[0]>=p||x[1]>=p) return 0;
	int b=(x[1]-x[0]*a)%p; if(b<0) b+=p;
	FORSZ(i,2,x) if(x[i]!=(a*x[i-1]+b)%p) return 0;
	int cur=(a*x.back()+b)%p;
	if(cur==res) return 0;
//	printf("a=%d p=%d -> %d\n",a,p,cur);
	res=cur; return 1;
}

void run(int casenr) {
	int maxd,n; scanf("%d%d",&maxd,&n);
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	int maxp=1; REP(i,maxd) maxp*=10;
	vector<bool> isprime(maxp+1,true); isprime[0]=isprime[1]=false;
	REPSZ(i,isprime) if(isprime[i]) for(int j=i+i;j<SZ(isprime);j+=i) isprime[j]=false;
	
	int cnt=0,res=-1;
	REPSZ(p,isprime) if(isprime[p]) {
		REP(a,p) {
			cnt+=calc(a,x,p,res);
		}
	}
//	printf("%d\n",cnt);
	if(cnt==1) printf("Case #%d: %d\n",casenr,res);
	else printf("Case #%d: I don't know.\n",casenr);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}
