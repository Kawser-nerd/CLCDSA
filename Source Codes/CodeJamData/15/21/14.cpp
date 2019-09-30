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

ll want;
int d[20],nd;
ll p10[20];

ll calc() {
	nd=0; for(ll cur=want;cur!=0;cur/=10) d[nd++]=cur%10; reverse(d,d+nd);
	if(nd==1) return want;

	ll ret=10; int havelen=2;
	while(havelen<nd) {
		int a=(havelen+1)/2,b=havelen-a;
		ret+=p10[a]-1+1+p10[b]-2+1; ++havelen;
		//printf("havelen=%d, ret=%lld\n",havelen,ret);
	}
	int z=nd-1; while(d[z]==0) --z;
	if(z==0&&d[0]==1) return ret;
	{
		ret++;
		int a=(nd+1)/2,b=nd-a;
		ll aval=0,bval=0;
		if(nd-z-1>=a) {
			aval+=p10[a];
			int y=b-1; while(d[y]==0) d[y--]=9; --d[y];
		}
		REP(i,b) bval+=p10[i]*d[i];
		REP(i,a) aval+=p10[i]*d[nd-i-1];
		if(bval>1) ret+=bval-1+1;
		ret+=aval-1;
		//printf("\t%d:%lld %d:%lld (%d)\n",a,aval,b,bval,z);
	}
	return ret;
}

const int MAXBF=1000000;
int dp[MAXBF+1],prv[MAXBF+1];

int c[20],nc;

void bf() {
	REPE(i,MAXBF) dp[i]=INT_MAX,prv[i]=-1; dp[1]=1;
	FOR(i,1,MAXBF) if(dp[i]!=INT_MAX) {
		if(dp[i]+1<dp[i+1]) dp[i+1]=dp[i]+1,prv[i+1]=i;
		nc=0; for(ll cur=i;cur!=0;cur/=10) c[nc++]=cur%10; reverse(c,c+nc); int j=0; REP(k,nc) j+=p10[k]*c[k]; if(dp[i]+1<dp[j]) dp[j]=dp[i]+1,prv[j]=i;
	}
}

void run(int casenr) {
	scanf("%lld",&want);
	printf("Case #%d: %lld\n",casenr,calc());
}

int main() {
	p10[0]=1; FOR(i,1,20) p10[i]=10*p10[i-1];

	/*bf();
	FORE(i,1,MAXBF) {
		want=i; ll a=calc(),b=dp[i];
		if(a!=b) { 
			printf("%d: bf=%lld calc=%lld\n",i,b,a); 
			for(int x=i;x!=-1;x=prv[x]) printf("%d ",x); puts("");
			break;
		}
	}*/

	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
