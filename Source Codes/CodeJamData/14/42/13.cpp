#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int dt[1024][1204]; // sorted i used, empty space begin
vector<pair<int,int>> a;

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		scanf("%d",&n);
		a.clear();
		for(int i = 0; i < n; i++) {
			int dat;
			scanf("%d",&dat);
			int fncnt = 0;
			for(int j = 0; j < i; j++) {
				if (a[j].first > dat){ 
					fncnt++;
				}
			}
			a.emplace_back(dat, fncnt);
		}
		sort(a.begin(),a.end());
		dt[0][0] = abs(n-1 - a[0].second);
		dt[0][1] = abs(a[0].second);
		for(int i = 1; i < n-1; i++) {
			for(int j = 0; j <= i+1; j++) {
				// dt[i-1][j] (append back)
				// dt[i-1][j-1] (front)
				int val = INT_MAX;
				if (j <= i) {
					val = min(val, abs((n-1-(i-j))-(a[i].second + j)) + dt[i-1][j]);
				}
				if (j > 0) {
					val = min(val, abs((j-1)-(a[i].second + j-1)) + dt[i-1][j-1]);
				}
				dt[i][j] = val;
			}
		}
		if (n == 1) {
			printf("Case #%d: 0\n", testcase);
		} else {
			int ans = dt[n-2][0];
			for(int i = 0; i < n; i++) {
				ans = min(dt[n-2][i], ans);
			}
			printf("Case #%d: %d\n", testcase, ans);
		}
	}
	return 0;
}
