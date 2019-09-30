#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define memset0(x) memset(x, 0, sizeof (x));

int TC, TCC;

int N;
vector<int> Tree[2005];

void init () {
	for(int i = 1; i <= 2000; i++) Tree[i].clear();
}

int DFS (int u, int p = -1) {
	if(Tree[u].size() - (p != -1) <= 1) return 1;
	int max1 = -1, max2 = -2;
	for(int e = 0; e < Tree[u].size(); e++) {
		int v = Tree[u][e];
		if(v != p) {
			int r = DFS(v, u);
			if(r > max1) max2 = max1, max1 = r;
			else if(r > max2) max2 = r;
		}
	}
	return max1 + max2 + 1;
}

void solve () {
	scanf("%d", &N);
	for(int i = 1; i <= N-1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	int res = N;
	for(int i = 1; i <= N; i++) res = min(res, N - DFS(i));
	printf("Case #%d: %d\n", TCC, res);
}

int main() {
	freopen("C:\\Users\\tncks0121\\Downloads\\B-large (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &TC);
	while(++TCC <= TC) {
		init();
		solve();
	}
	return 0;
}