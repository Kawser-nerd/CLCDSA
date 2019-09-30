#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000000007ll

ll C[110][110];
ll dp[110];

ll func(vector <int> v, int N){ // N <= 100
	int sz=v.size(),i,j;
	
	REP(i,N+1){
		dp[i] = 1;
		REP(j,sz) dp[i] = dp[i] * C[i][v[j]] % MOD;
		REP(j,i) dp[i] = (dp[i] - dp[j] * C[i][j] % MOD + MOD) % MOD;
	}
	
	return dp[N];
}

int V;
int child[110000][30];
int sz[110000];
bool contain[110000];

void main2(void){
	int N,K,i,j;
	string s;
	
	REP(i,110000) REP(j,30) child[i][j] = -1;
	REP(i,110000) sz[i] = 0;
	REP(i,110000) contain[i] = false;
	V = 1;
	
	cin >> N >> K;
	REP(i,N){
		cin >> s;
		int cur = 0;
		REP(j,s.length()){
			int c = s[j] - 'A';
			if(child[cur][c] == -1){
				child[cur][c] = V;
				V++;
			}
			cur = child[cur][c];
		}
		contain[cur] = true;
	}
	
	// cout << V << endl;
	
	int ans = 0;
	ll prod = 1;
	
	for(i=V-1;i>=0;i--){
		sz[i] = 0;
		if(contain[i]) sz[i] = 1;
		
		vector <int> v;
		if(contain[i]) v.push_back(1);
		REP(j,26) if(child[i][j] != -1){
			int tmp = child[i][j];
			v.push_back(sz[tmp]);
			sz[i] = min(sz[i] + sz[tmp], K);
		}
		
		ans += sz[i];
		ll tmp = func(v, sz[i]);
		prod = prod * tmp % MOD;
	}
	
	cout << ans << ' ' << prod << endl;
}

int main(void){
	int i,j;
	REP(i,110) REP(j,i+1){
		if(j == 0 || j == i) C[i][j] = 1;
		else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}

	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
