#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int t;
int n, a[1005];
int indeg[1005];
vector<int> gph[1005];

bool vis[1005];

int dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	return 1 + dfs(a[x]);
}

int dfs2(int x){
	int ret= 1;
	for(auto &j : gph[x]){
		if(indeg[j] == 0){
			ret = max(ret, dfs2(j) + 1);
		}
	}
	return ret;
}

int main(){
	cin >> t;
	for(int i=1; i<=t; i++){
		printf("Case #%d: ", i);
		memset(indeg, 0, sizeof(indeg));
		for(int i=0; i<=1000; i++) gph[i].clear();
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> a[i];
			indeg[a[i]]++;
			gph[a[i]].push_back(i);
		}
		queue<int> que;
		for(int i=1; i<=n; i++){
			if(indeg[i] == 0) que.push(i);
		}
		while(!que.empty()){
			int x = que.front();
			que.pop();
			indeg[a[x]]--;
			if(indeg[a[x]] == 0){
				que.push(a[x]);
			}
		}
		// calculate biggest cycle
		int ret = 0, ret2 = 0;
		for(int i=1; i<=n; i++){
			if(indeg[i]){
			memset(vis, 0, sizeof(vis));
				int t = dfs(i);
				ret = max(ret, t);
				if(t == 2){
					int u = i, v = a[i];
					ret2 += dfs2(u) + dfs2(v);
				}
			}
		}
		ret = max(ret, ret2/2);
		printf("%d\n",ret);
	}
}