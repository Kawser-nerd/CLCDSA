#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, E, T;
	while(cin >> N >> E >> T){
		long long res = E;
		vector<int> x(N);
		for(int i=0;i<N;i++) cin >> x[i];
		vector<long long> dp(N+1);
		vector<long long> dp2(N);
		dp[N-1] = E+T; dp[N] = E;
		dp2[N-1] = dp[N] + 2*x[N-1];
		int thr = N-1;
		for(int i=N-2;i>=0;i--){
			while(2*(x[thr] - x[i]) > T) --thr;
			dp[i] = T+dp[thr+1];
			if(thr+1 < N) dp[i] = min(dp[i], dp2[thr+1]-2*x[i]);
			dp2[i] = min(dp2[i+1], dp[i+1] + 2*x[i]);
		}
		cout << dp[0] << endl;
	}
}