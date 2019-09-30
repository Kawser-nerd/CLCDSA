#include <vector>
#include <iostream>
using namespace std;

using L = unsigned long long int;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> cond(n, vector<bool>(n, false));
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		cond[x-1][y-1] = true; // x?y????
	}
	vector<L> dp(1<<n, 0);
	dp[0] = 1;
	for(int mask = 0; mask < 1<<n; mask++){
		for(int i = 0; i < n; i++){ // i: ??????????
			if((mask >> i) & 1) continue;
			bool flag = true;
			for(int j = 0; j < n; j++){ // j: ??????????????
				if(i != j && (mask >> j) & 1 && cond[i][j]){ // j?????????? ?? i?j???? ? ???
					flag = false;
					break;
				}
			}
			if(flag){
				dp[mask | (1 << i)] += dp[mask];
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
}