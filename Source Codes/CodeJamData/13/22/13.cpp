#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

double dp[2000][2000];

double solve(int N, int X, int Y){
	int place = (abs(X)+abs(Y))/2;
	int sum = 0;
	for(int i=0;i<place;i++){
		sum += 4*i+1;
		if(sum > N) return 0; 
	}
	if(sum > N) return 0;
	if(sum + 4*place+1 <= N) return 1.0;
	for(int i=0;i<2000;i++)
		for(int j=0;j<2000;j++)
			dp[i][j] = 0;
	dp[0][0] = 1.0;
	for(int i=0;i<=2*place;i++){
		for(int j=0;j<=2*place;j++){
			if(i==2*place&&j==2*place) continue;
			if(i==2*place){
				dp[i][j+1] += dp[i][j];
			}
			else if(j==2*place){
				dp[i+1][j] += dp[i][j];
			}
			else {
				dp[i][j+1] += 0.5*dp[i][j];
				dp[i+1][j] += 0.5*dp[i][j];
			}
		}
	}
	int lest = N-sum;
	double res = 0;
	for(int i=abs(Y)+1;i<=lest;i++){
		if(i > 2*place || lest-i > 2*place) continue;
		res += dp[i][lest-i];
	}
	return res;
}

int main(){
	int T; cin >> T;
	int N, X, Y;
	for(int test=1;test<=T;test++){
		cin >> N >> X >> Y;
		printf("Case #%d: %.8lf\n", test, solve(N, X, Y));
	}
}