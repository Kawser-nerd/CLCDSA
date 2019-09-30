#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int dp[46][100000];
bool done[46][100000];
int res = 45;
int x,k;
int main(){
	cin >> k;
	dp[0][0] = 1;
	
	for(int sum = 0;sum < 46;sum++){
		for(int mod = 0;mod < k;mod++){
			if(dp[sum][mod] == 0)continue;
			int x = mod;
			while(!done[sum][x]){
				done[sum][x] = true;
				dp[sum][x*10%k] = 1;
				x = x*10%k;
			}
		}
		for(int mod = 0;mod < k;mod++){
			if(dp[sum][mod] == 0)continue;
			if(mod == 0 && sum != 0){
				cout << sum << endl;
				return 0;
			}
			for(int dig = 1;dig < 10;dig++){
				if(sum + dig > 45)continue;
				dp[sum+dig][(mod*10+dig)%k] = 1;
			}
		}
	}
	return 0;
}