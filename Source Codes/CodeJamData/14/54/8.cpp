#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int n;
int score[128];
int dt[128][128];
vector<int> gnext[128];

int used[128][128];
int usedscore[128];
int maxScore(int s, int e, int turn, bool failed) {
	int ret;
	if (turn == 0) {
		bool mayUse = (usedscore[s] == 0);
		usedscore[s] = 1;
		ret = INT_MIN;
		for(int i = 0; i < gnext[s].size(); i++) {
			int next = gnext[s][i];
			if (used[s][next]) continue;
			used[s][next] = used[next][s] = 1;
			ret = max(ret, maxScore(next, e, turn^(failed ? 0 : 1), failed));
			used[s][next] = used[next][s] = 0;
		}
		if (ret == INT_MIN) {
			if (failed) {
				ret = 0;
			} else {
				ret = maxScore(s, e, turn^1, true);
			}
		}
		if (mayUse) {
			ret += score[s];
			usedscore[s] = 0;
		}
	}else {
		bool mayUse = (usedscore[e] == 0);
		usedscore[e] = 1;
		ret = INT_MAX;
		for(int i = 0; i < gnext[e].size(); i++) {
			int next = gnext[e][i];
			if (used[e][next]) continue;
			used[e][next] = used[next][e] = 1;
			ret = min(ret, maxScore(s, next, turn^(failed ? 0 : 1), failed));
			used[e][next] = used[next][e] = 0;
		}
		if (ret == INT_MAX) {
			if (failed) {
				ret = 0;
			} else {
				ret = maxScore(s, e, turn^1, true);
			}
		}
		if (mayUse) {
			ret -= score[e];
			usedscore[e] = 0;
		}
	}
	return ret;
}

int calcScore(int s1, int s2){
	memset(dt,-1,sizeof(dt));
	memset(used, 0, sizeof(used));
	memset(usedscore, 0, sizeof(usedscore));
	return maxScore(s1,s2,0,false);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1 ;testcase <=T; testcase++) {
		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			scanf("%d",&score[i]);
			gnext[i].clear();
		}
		for(int i = 0; i < n-1;i++){
			int a,b;
			scanf("%d",&a);
			a--;
			gnext[i].push_back(a);
			gnext[a].push_back(i);
		}

		int ans = INT_MIN;
		for(int i = 0; i < n; i++) { // starting!
			int mySt = INT_MAX;
			for(int j = 0; j < n; j++) { 
				int cur = calcScore(i, j);
				mySt = min(mySt, cur);
			}
			ans = max(ans, mySt);
		}

		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}