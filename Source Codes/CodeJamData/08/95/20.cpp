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
#define FOR(i,a,b) for(int i=(a);i<int(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=int(b);++i) 
#define REPE(i,n) FORE(i,0,n) 
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) FORSZ(i,0,v) 
#define VAR(a,b) __typeof(b) a=b 
#define FORIT(it,v) for(VAR(it,(v).begin());it!=(v).end();++(it)) 
#define DIST(a,b) ABS((a)-(b)) 
#define BETWEEN(i,a,b) ((a)<=(i)&&(i)<(b)) 
#define SQR(a) ((a)*(a)) 
#define ALL(v) (v).begin(),(v).end() 
#define SORT(v) sort(ALL(v)) 
#define UNIQUE(v) (v).erase(unique(ALL(v)),(v).end()) 
typedef long long ll; 
typedef vector<string> VS; 
typedef vector<VS> VVS; 
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef vector<double> VD; 
typedef vector<VD> VVD; 
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL; 
typedef pair<int,int> PII; 
typedef vector<PII> VPII;

int R,C;
char g[52][52];
int DR[]={-1,0,+1,0},DC[]={0,+1,0,-1};

int dp[15][15][1<<15];

void run(int casenr) {
	scanf("%d%d",&R,&C);
	memset(g,'.',sizeof(g));
	REP(r,R) REP(c,C) { char z; do { scanf("%c",&z); } while(z!='.'&&z!='#'&&z!='?'); g[r][c]=z; }
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	int ret=0;
	REP(r,R) REP(c,C) REP(m,1<<C) if(dp[r][c][m]!=-1) {
		REP(x,2) {
			if(g[r][c]=='.'&&x==1) continue;
			if(g[r][c]=='#'&&x==0) continue;
			int cur=dp[r][c][m];
			if(x!=((m>>c)&1)) ++cur;
			if(c==0&&x==1||c>0&&x!=((m>>(c-1))&1)) ++cur;
			if(r+1==R&&x==1) ++cur;
			if(c+1==C&&x==1) ++cur;
			int nm=m; nm&=~(1<<c); nm|=x<<c;
			if(c+1<C) dp[r][c+1][nm]>?=cur;
			else if(r+1<R) dp[r+1][0][nm]>?=cur;
			else ret>?=cur;
		}
	}
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
