#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

bool xy[16][16];

ll solve(int used, vector<ll>& dp){
	if(dp[used] != -1){ return dp[used]; }
	dp[used] = 0;
	//i is the last
	for(int i=0;i<16;i++){
		if(!((used >> i) & 1)){ continue; }
		bool ok = true;
		for(int j=0;j<16;j++){
			if(!((used >> j) & 1)){ continue; }
			if(xy[i][j]){
				ok = false;
				break;
			}
		}
		if(!ok){ continue; }
		
		dp[used] += solve(used ^ (1<<i), dp);
	}
	return dp[used];
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<ll> dp(1<<16, -1);
	dp[0] = 1;
	for(int i=0;i<m;i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		xy[x][y] = true;
	}

	ll ret = solve((1<<n) - 1, dp);

	cout << ret << endl;
	return 0;
}