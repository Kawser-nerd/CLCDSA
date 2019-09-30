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


void run(int casenr) {
	int n; scanf("%d",&n);
	vector<ll> x(n); REP(i,n) scanf("%lld",&x[i]);
	int n1=n/2,n2=n-n1;
	vector<pair<ll,int> > a,b;
	REP(i,n1) FOR(j,i+1,n1) FOR(k,j+1,n1) a.PB(MP(x[i]+x[j]+x[k],(1+i)+1000*(1+j)+1000000*(1+k)));
	REP(i,n2) FOR(j,i+1,n2) FOR(k,j+1,n2) b.PB(MP(x[n1+i]+x[n1+j]+x[n1+k],(1+n1+i)+1000*(1+n1+j)+1000000*(1+n1+k)));
	sort(a.begin(),a.end()); sort(b.begin(),b.end());

/*	for(int i=0;i<SZ(a)||i<SZ(b);++i) {
		if(i<SZ(a)) printf("%10lld",a[i].first); else printf("          "); 
		printf(" ");
		if(i<SZ(b)) printf("%10lld",b[i].first); else printf("          "); 
		puts("");
	}*/

	vector<int> adiff(1000,-1);
	vector<int> bdiff(1000,-1);
	FORSZ(i,1,a) { ll cur=a[i].first-a[i-1].first; if(cur<1000) adiff[cur]=i; }
	FORSZ(i,1,b) { ll cur=b[i].first-b[i-1].first; if(cur<1000) bdiff[cur]=i; }
	REP(i,1000) if(adiff[i]!=-1&&bdiff[i]!=-1) {
		vector<int> dig1; for(int z=a[adiff[i]-1].second;z>0;z/=1000) dig1.PB(z%1000-1);
		vector<int> dig2; for(int z=a[adiff[i]].second;z>0;z/=1000) dig2.PB(z%1000-1);
		for(int z=b[bdiff[i]-1].second;z>0;z/=1000) dig2.PB(z%1000-1);
		for(int z=b[bdiff[i]].second;z>0;z/=1000) dig1.PB(z%1000-1);
		printf("Case #%d:\n",casenr);
//		printf("%d %d | %d %d\n",a[adiff[i]-1].second,b[bdiff[i]].second,a[adiff[i]].second,b[bdiff[i]-1].second);
		bool first1=true; ll sum1=0; REPSZ(j,dig1) { if(first1) first1=false; else printf(" "); printf("%lld",x[dig1[j]]); sum1+=x[dig1[j]]; } puts("");
		bool first2=true; ll sum2=0; REPSZ(j,dig2) { if(first2) first2=false; else printf(" "); printf("%lld",x[dig2[j]]); sum2+=x[dig2[j]]; } puts("");
		if(sum1!=sum2) { printf("diff!!!! %lld vs %lld\n",sum1,sum2); assert(false); }
		return;
	}
	printf("Case #%d:\nImpossible\n",casenr);
	assert(false);
}

/*
void run(int casenr) {
	int n; scanf("%d",&n);
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	map<int,vector<int> > ways;
	FOR(i,1,1<<n) {
		int sum=0; REP(j,n) if(i&(1<<j)) sum+=x[j];
		ways[sum].PB(i);
	}
	for(map<int,vector<int> >::iterator i=ways.begin();i!=ways.end();++i) {
		REPSZ(j,i->second) FORSZ(k,j+1,i->second) if((i->second[j]&i->second[k])==0) {
			printf("Case #%d:\n",casenr);
			int a=i->second[j]; bool firsta=true; REP(q,n) if(a&(1<<q)) { if(firsta) firsta=false; else printf(" "); printf("%d",x[q]); } puts("");
			int b=i->second[k]; bool firstb=true; REP(q,n) if(b&(1<<q)) { if(firstb) firstb=false; else printf(" "); printf("%d",x[q]); } puts("");
			return;
		}
	}
	printf("Case #%d:\nImpossible\n",casenr);
}
*/

void gen() {
	int t=100;
	printf("%d\n",t);
	REP(tt,t) {
		int n=500;
		vector<ll> q; REP(i,n) { int x=rand()%10000,y=rand()%10000,z=rand()%10000; q.PB((ll)100000000*x+(ll)10000*y+(ll)z); }
		printf("%d ",n); REP(i,n) { if(i!=0) printf(" "); printf("%lld",q[i]); } puts("");
	}
	exit(0);
}

int main() {
//gen();


	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}

 
