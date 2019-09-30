#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN=55;
#define ld long double

int T,N,C;
long double combo[MAXN][MAXN];
inline void process() {
	combo[0][0]=1;
	for(int i=1;i<MAXN;i++) {
		combo[i][0]=1;
		for(int j=1;j<=i;j++) {
			combo[i][j]=combo[i-1][j]+combo[i-1][j-1];
		}
	}
}

long double dp[MAXN];

inline ld choose(int n,int k) {
	if (k<0) {return 0.0;}
	if (k>n) {return 0.0;}
	return combo[n][k];
}

int main() {
	process();
	scanf("%d",&T);
	for(int t=1;t<=T;t++) {
		scanf("%d %d ",&C,&N);
		assert(C>=N);
		dp[C]=0;
		for(int k=C-1;k>=0;k--) {
			ld sum=1;
			for(int i=1;i<=min(C-k,N);i++) {
				sum+=((dp[k+i]*choose(k,N-i)*choose(C-k,i))/choose(C,N));
			}
			sum/=(((ld)1.0)-(choose(k,N)/choose(C,N)));
			dp[k]=sum;
		}		
		printf("Case #%d: %.12Lf\n",t,dp[0]);
	}
	return 0;
}
