#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>

#define FOR(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define FORD(i,a,b) for(int i=(a)-1; i>=(int)(b); --i)
#define FORE(i,C) for(__typeof(C.begin()) i=C.begin(); i!=C.end(); ++i)
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

typedef long long LL;

const int kMax = 16;
const int nMax = 50005;

int tabN[kMax][kMax];
int tabP[kMax][kMax];
char S[nMax];
int K;

int dp[kMax][kMax][1<<kMax];

int go(int act, int last, int mask) {
	int &res = dp[act][last][mask];
	if(res>=0) return res;
	if(mask==(1<<K)-1) return res = tabN[act][last];
	res = 0;
	FOR(i,0,K) if((mask&(1<<i))==0)
		res >?= go(i,last,mask+(1<<i)) + tabN[act][i];
	return res;
}

void testcase(int tNum) {

	scanf("%d",&K);
	FOR(i,0,K) FOR(j,0,K) tabN[i][j] = tabP[i][j] = 0;
	
	scanf("%s",S);
	int N = strlen(S);
	
	for(int p=0; p<N; p+=K) {
		FOR(i,0,K) FOR(j,i+1,K) if(S[p+i]==S[p+j]) {
			tabN[i][j]++;
			tabN[j][i]++;
		}
		if(p+K<N) FOR(i,0,K) FOR(j,0,K) if(S[p+i]==S[p+K+j]) tabP[j][i]++;
	}
	
	int res = 0;
	memset(dp,-1,sizeof(dp));
	
	FOR(i,0,K) FOR(j,0,K) if(i!=j) res >?= tabP[i][j] + go(i,j,(1<<i)+(1<<j));
	
	res = N-res;
	
	printf("Case #%d: %d\n",tNum,res);
	
}

int main() {

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
