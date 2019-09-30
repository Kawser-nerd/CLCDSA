#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<queue>

#define FOR(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define FORE(it,C) for(__typeof(C.begin()) it=C.begin(); it!=C.end(); ++it)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef long double LD;

using namespace std;

LD fact[41];
LD newton[41][41];

LD dp[41][41];
LD res[41];
LD prob[41];

void testcase(int testNr) {
	int N,C;
	scanf("%d %d",&C,&N);
	
	FOR(i,1,C+1) FOR(j,i,min(i+N,C)+1) {
		int k = j-i;
		dp[i][j] = (newton[N-k][i] * newton[k][C-i]) / newton[N][C];
	}
	
	FOR(i,0,C+1)
	{
		res[i] = 0.0;
		prob[i] = 0.0;
	}
	
	res[N] = 1.0;
	prob[N] = 1.0;
	FOR(i,N,C) {
		LD cyc = prob[i] / (1-dp[i][i]);
		//printf("  res[%d] = %.3llf prob=%.3llf cyc=%.3llf\n",i,res[i],prob[i],cyc);
		FOR(j,i+1,min(i+N,C)+1)
		{
			res[j] += (res[i]+cyc)*(dp[i][j]/(1-dp[i][i]));
			prob[j] += prob[i]*(dp[i][j]/(1-dp[i][i]));
		}
	}
	
	printf("Case #%d: %.7llf\n",testNr, res[C]);
}

int main() {
	fact[0] = fact[1] = 1.0;
	FOR(i,2,41) fact[i] = i*fact[i-1];
	
	FOR(i,0,41) FOR(j,i,41)
		newton[i][j] = fact[j] / (fact[i]*fact[j-i]);

	int t;
	scanf("%d",&t);
	FOR(i,0,t)
		testcase(i+1);
}
