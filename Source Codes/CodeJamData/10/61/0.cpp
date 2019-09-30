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

int n;
char s[7001];

int dp[2][6][7001];

char pp[6][4]={"ABC","ACB","BAC","BCA","CAB","CBA"};

char current(int p,int len) {
	if(len<=0) return '?';
	len%=3;
	return pp[p][len];
}

void run(int casenr) {
	scanf("%s",s); n=strlen(s);
	
//	n=7000; REP(i,n) s[i]='A'+(rand()%3); s[n]='\0';
	
	int a=0; memset(dp[a],-1,sizeof(dp[a])); REP(p,6) dp[a][p][0]=0;
	#define UPDATE(dst,val) if(dst==-1||val<dst) dst=val;
	REP(i,n) {
		memset(dp[!a],-1,sizeof(dp[!a]));
		REP(p,6) REPE(len,n) if(dp[a][p][len]!=-1) {
			if(current(p,len)==s[i]) {
				UPDATE(dp[!a][p][len],dp[a][p][len]+1);
			} else if(current(p,len-1)==s[i]) {
				UPDATE(dp[!a][p][len-1],dp[a][p][len]+2);
			} else if(current(p,len+1)==s[i]) {
				UPDATE(dp[!a][p][len+1],dp[a][p][len]+2);
			}
		}
		a=!a;
		REP(p,6) for(int len=n;len>0;--len) if(dp[a][p][len]!=-1) UPDATE(dp[a][p][len-1],dp[a][p][len]+1);
		REP(p,6) if(dp[a][p][0]!=-1) REP(np,6) UPDATE(dp[a][np][0],dp[a][p][0]);
		REP(p,6) if(dp[a][p][1]!=-1) REP(np,6) if(current(p,1)==current(np,1)) UPDATE(dp[a][np][1],dp[a][p][1]);
//		REP(p,6) REPE(len,n) if(dp[a][p][len]!=-1) printf("after %d: perm=%s, len=%d -> %d\n",i+1,pp[p],len,dp[a][p][len]);
	}
	int ret=-1;
	REP(p,6) UPDATE(ret,dp[a][p][0]);
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}
