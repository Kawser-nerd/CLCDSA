#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int N,K;
double p[210];
double q[210];
double dp[210][210];

double func(void){
	int i,j;
	
	REP(i,K+1) REP(j,K+1) dp[i][j] = 0.0;
	dp[0][0] = 1.0;
	
	REP(i,K) REP(j,i+1) if(dp[i][j] > 1.0E-100){
		dp[i+1][j] += dp[i][j] * (1.0 - q[i]);
		dp[i+1][j+1] += dp[i][j] * q[i];
	}
	
	return dp[K][K/2];
}

void main2(void){
	int i,j;
	
	cin >> N >> K;
	REP(i,N) cin >> p[i];
	
	sort(p, p+N);
	
	double ans = 0.0;
	
	REP(i,K+1){
		int sz = 0;
		REP(j,i){
			q[sz] = p[j];
			sz++;
		}
		REP(j,K-i){
			q[sz] = p[N-1-j];
			sz++;
		}
		double tmp = func();
		ans = max(ans, tmp);
	}
	
	printf("%.9f\n", ans);
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
