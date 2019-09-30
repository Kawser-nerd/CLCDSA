#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 1e5 + 1;
constexpr int MOD = 1e9 + 7;

using int64 = int64_t;
#define int int64

vector<int> edge[MAX_N];
int memo_f[MAX_N];
int memo_g[MAX_N];

int f(int, int);
int g(int, int);

int g(int x, int parent){
	if(memo_g[x] > 0) return memo_g[x];
	
	int cnt = 1;
	for(auto &&child: edge[x]){
		if (child == parent) continue;
		
		(cnt *= f(child, x) % MOD) %= MOD;
	}
	
	return memo_g[x] = cnt;
}

int f(int x, int parent){
	if (memo_f[x] > 0) return memo_f[x];
	
	int white = g(x,parent);
	int black = 1;
	for(auto &&child: edge[x]){
		if (child == parent) continue;
		
		(black *= g(child, x) % MOD) %= MOD;
	}
	return memo_f[x] = (white + black) % MOD;	
}


signed main() {
	int n; cin >> n;
	for(int i=0;i<n-1;++i) {
		int fr,to; cin >> fr >> to;
		edge[fr-1].push_back(to-1);
		edge[to-1].push_back(fr-1);
	}
	
	int ans = f(0, -1);
	cout << ans << endl;
	
	return 0;
}