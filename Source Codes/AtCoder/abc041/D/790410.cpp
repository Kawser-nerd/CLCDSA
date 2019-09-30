#include <iostream>
#include <cstring>

using namespace std;

long long dp[1<<16];

int main(){
	int fast[16];
	int N, M;
	while(cin >> N >> M){
		memset(dp, 0, sizeof(dp));
		memset(fast, 0, sizeof(fast));
		for(int i=0;i<M;i++){
			int x, y; cin >> x >> y;
			--x; --y;
			fast[y] |= 1<<x;
		}
		dp[0] = 1;
		for(int S=0;S<(1<<N);S++){
			for(int i=0;i<N;i++){
				if(S&(1<<i)) continue;
				if((S&fast[i])==fast[i]) dp[S|(1<<i)] += dp[S];
			}
		}
		cout << dp[(1<<N)-1] << endl;
	}
}