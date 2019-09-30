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

double dp[1500][1500];

double main2(void){
	int N,x,y,t,i,j;
	
	cin >> N >> x >> y;
	
	if(x < 0) x = -x;
	for(t=0;;t+=2){
		if(N <= 2*t+1) break;
		N -= 2*t+1;
	}
	
	if(x+y > t) return 0.0;
	if(x+y < t) return 1.0;
	
	if(N == 2*t+1) return 1.0;
	if(y == t) return 0.0;
	
	REP(i,t+1) REP(j,t+1) dp[i][j] = 0.0;
	dp[0][0] = 1.0;
	
	REP(i,t+1) REP(j,t+1){
		if(i == t && j < t) dp[i][j+1] += dp[i][j];
		if(i < t && j == t) dp[i+1][j] += dp[i][j];
		if(i < t && j < t){
			dp[i+1][j] += dp[i][j] / 2.0;
			dp[i][j+1] += dp[i][j] / 2.0;
		}
	}
	
	double ans = 0.0;
	REP(i,t+1) REP(j,t+1) if(i+j == N && i > y) ans += dp[i][j];
	return ans;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		double ans = main2();
		printf("Case #%d: %.9f\n", tc+1, ans);
	}
	return 0;
}
