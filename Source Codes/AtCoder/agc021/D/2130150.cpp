#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int k;

int dp[324][324][324];

int main(){
	cin >> s >> k;
	int n = s.size();
	s = "*" + s;
	for(int i = 0;i < 324;i++)
		for(int j = 0;j < 324;j++)
			for(int k = 0;k < 324;k++)
				dp[i][j][k] = -100000;
	
	dp[0][n+1][0] = 0;
	for(int i = 0;i <= n;i++){
		for(int j = n+1;j > i;j--){
			for(int k = 0;k <= n;k++){
				if(i > 0)dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i][j+1][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i][j+1][k]);
				int cost = s[i] != s[j];
				if(k-cost >= 0 && i > 0)
					 dp[i][j][k] = max(dp[i][j][k], dp[i-1][j+1][k-cost] + 1);
			}
		}
	}
	int res = 0;
	for(int i = 1;i <= n+1;i++){
		for(int j = 0;j <= k;j++){
			res = max(res, dp[i-1][i+1][j] * 2 + 1);
			res = max(res, dp[i-1][i][j]*2);
		}
	}

	cout << res << endl;
	return 0;
}