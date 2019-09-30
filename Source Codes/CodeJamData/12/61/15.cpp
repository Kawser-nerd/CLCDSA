#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define INF (1ll<<60)
#define _abs(x) ((x)>0?(x):-(x))

int N;
ll x[110],y[110],t[110];
ll dp[110][110]; // smashed, pos -> min time

ll dist(ll x1, ll y1, ll x2, ll y2){
	return max(_abs(x1-x2), _abs(y1-y2));
}

void main2(void){
	int i,j,k;
	
	cin >> N;
	REP(i,N) cin >> x[i] >> y[i] >> t[i];
	
	REP(i,N+1) REP(j,N) dp[i][j] = INF;
	
	REP(i,N){
		ll tmp = max(dist(0,0,x[i],y[i]) * 100, t[i]);
		if(tmp <= t[i] + 1000) dp[1][i] = min(dp[1][i], tmp);
	}
	
	REP(i,N) REP(j,N) if(dp[i][j] != INF) REP(k,N) if(k != j){
		ll tmp = max(dp[i][j] + max(dist(x[j],y[j],x[k],y[k]) * 100, 750ll), t[k]);
		if(tmp <= t[k] + 1000) dp[i+1][k] = min(dp[i+1][k], tmp);
	}
	
	int ans = 0;
	REP(i,N+1) REP(j,N) if(dp[i][j] != INF) ans = max(ans,i);
	cout << ans << endl;
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
