#include <iostream>
#include <vector>
using namespace std;


int X[1010];
vector<int> ch[1010];

pair<int,int> dfs(int root){
	vector<int> dp(5010, 1e9);

	dp[0] = 0;
	for(int c : ch[root]){
		vector<int> ndp(5010, 1e9);
		int w,b;
		tie(w,b) = dfs(c);
		for(int i = 5000 ; i >= X[c] ; i--){
			ndp[i] = min(ndp[i], dp[i-X[c]] + w);
		}
		for(int i = 5000 ; i >= b ; i--){
			ndp[i] = min(ndp[i], dp[i-b] + X[c]);
		}
		dp = ndp;
	}
	int minB = 1000000000, minW = 1000000000;
	for(int i = 0 ; i <= X[root] ; i++)
		minW = min(dp[i], minW);
	

	for(int i = 0 ; i <= 5000 ; i++)
		if( dp[i] <= X[root] ){
			minB = min(i, minB);
		}
	return make_pair(minW, minB);
}

int main(){
	int N;
	cin >> N;
	for(int i = 1 ; i < N ; i++){
		int p;
		cin >> p;
		ch[--p].push_back(i);
	}
	for(int i = 0 ; i < N ; i++) cin >> X[i];

	auto p = dfs(0);
	int mn = min(p.first,p.second);
	if( mn < 1e9 ) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
}