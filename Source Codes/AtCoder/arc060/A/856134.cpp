#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<cstring>
using namespace std;
using ulong = unsigned long;
using ll = long long;

int n, a;
vector<int> xs;
ll memo[51][51][2501];
ll solve(int idx, int cnt, int sum){
	if(memo[idx][cnt][sum] != -1){ return memo[idx][cnt][sum]; }
	if(idx == n){
		return sum && sum == cnt * a;
	}
	return memo[idx][cnt][sum] =
		solve(idx + 1, cnt, sum) +
		solve(idx + 1, cnt + 1, sum + xs[idx]);
}

ll ptrns[50][2501];
int main(){
	cin >> n >> a;
	xs.resize(n);
	for(int i=0;i<n;i++){
		cin >> xs[i];
	}
	memset(memo, -1, sizeof(memo));
	cout << solve(1, 0, 0) + solve(1, 1, xs[0]) << endl;

	return 0;
}