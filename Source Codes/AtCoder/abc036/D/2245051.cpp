#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>

#define BIT(a) (1 << (a))

using namespace std;

long long MOD = 1000000007;

vector<int> edge[100005];
vector<int> child[100005];
int dp[100005][2];

void dfs(int crt, int parent){
	for (auto itr = edge[crt].begin(); itr != edge[crt].end(); itr++){
		if (*itr != parent){
			child[crt].push_back(*itr);
			dfs(*itr, crt);
		}
	}
}

long long rec(int crt, int color){
	if (dp[crt][color] != 0) return dp[crt][color];

	long long res = 1;
	for (auto itr = child[crt].begin(); itr != child[crt].end(); itr++){
		if (color){
			res *= rec(*itr, 0);
		}else{
			res *= rec(*itr, 0) + rec(*itr, 1);
		}
		res %= MOD;
	}
	return dp[crt][color] = res;
}


int main(void){
	int N;
	cin >> N;
	for (int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1, 0);
	
	cout << (rec(1, 0) + rec(1, 1)) % MOD << endl;
	return 0;

}