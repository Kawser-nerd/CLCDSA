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

int n; ll have;
vector<ll> x;
vector<vector<ll> > tmp;

inline ll cost(int a,int b) { ll ret=x[a]-x[b]; if(ret<0) ret=-ret; return ret; }

void go(int at,int cnt,ll sofar) {
	if(at==0) { tmp[cnt].PB(sofar); return; }
	ll d=x[at]-x[at-1]; if(d<0) d=-d;
	go(at-1,cnt+1,sofar+2*(cnt+1)*d);
	if(cnt>=1) go(at-1,cnt,sofar+2*cnt*d);
	if(cnt>=2) go(at-1,cnt-1,sofar+2*(cnt-1)*d);
}

vector<vector<ll> > calc(vector<ll> xx) {
	x=xx; n=SZ(x);
	tmp=vector<vector<ll> >(n);
	go(n-1,0,0);
	REPSZ(i,tmp) { vector<ll> &q=tmp[i]; sort(q.begin(),q.end()); q.erase(unique(q.begin(),q.end()),q.end()); }
	return tmp;
}

ll gobf(int at,int been,ll sofar) {
	if(sofar>have) return -1;
	if(been==(1<<n)-1) { ll ret=sofar+cost(at,0); return ret>have?-1:ret; }
	ll ret=-1;
	REP(to,n) if((been&(1<<to))==0) {
		ll cur=gobf(to,been|(1<<to),sofar+cost(at,to));
		if(cur!=-1&&(ret==-1||cur>ret)) ret=cur;
	}
//	printf("bf %d %x (%lld) = %lld\n",at,been,sofar,ret);
	return ret;
}

ll bf(vector<ll> xx) {
	x=xx; n=SZ(x);
	return gobf(0,1<<0,0);
}

void run(int casenr) {
	int n; scanf("%d",&n);
	vector<ll> x(n); REP(i,n) scanf("%lld",&x[i]); 
	scanf("%lld",&have);
	
//	n=30; x=vector<ll>(n); REP(i,n) x[i]=rand(); have=100000000000000000LL;
	
	sort(x.begin(),x.end());

	ll ret=-1;
	if(n==2) {
		ret=2*(x[1]-x[0]);
	} else {
		int mid=n/2;
		vector<ll> x1; for(int i=mid;i>=0;--i) x1.PB(x[i]);
		vector<ll> x2; for(int i=mid;i<n;++i) x2.PB(x[i]);
		
		vector<vector<ll> > a=calc(x1);
		vector<vector<ll> > b=calc(x2);
//		REPSZ(i,a) { printf("a %d:",i); REPSZ(j,a[i]) printf(" %lld",a[i][j]); puts(""); }
//		REPSZ(i,b) { printf("b %d:",i); REPSZ(j,b[i]) printf(" %lld",b[i][j]); puts(""); }
		
		for(int numleft=1;numleft<SZ(a);++numleft) {
			for(int numright=max(1,numleft-1);numright<=min(SZ(b)-1,numleft+1);++numright) {
//				printf("%d %d\n",numleft,numright);
				vector<ll> &A=a[numleft],&B=b[numright];
				int i=0,j=SZ(B)-1;
				while(i<SZ(A)&&j>=0) {
					ll cur=A[i]+B[j];
//					printf("\t%lld\n",cur);
					if(cur>have) { --j; continue; }
					if(cur>ret) ret=cur;
					++i;
				}
			}
		}
	}
	if(ret>have) ret=-1;
//	ll need=bf(x); if(ret!=need) printf("err: \n%lld\n vs \n%lld\n",ret,need);
	
	if(ret==-1) printf("Case #%d: NO SOLUTION\n",casenr); else printf("Case #%d: %lld\n",casenr,ret);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}
