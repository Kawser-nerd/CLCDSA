#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int h[102];
int g[102];

int dt[130][11][1003]; // current hitting monster, tower hit count, my remainings.

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		int p,q,n;
		scanf("%d%d%d",&p,&q,&n);
		
		for(int i = 0; i< n; i++) {
			scanf("%d%d",&h[i],&g[i]);
		}
		h[n] = 100000000;
		memset(dt, -1, sizeof(dt));
		dt[0][0][1] = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j*q < h[i]; j++) {
				for(int k = 0; k <= 1001; k++) {
					if (dt[i][j][k] == -1) continue;
					if ((j+1)*q < h[i]) {
						dt[i][j+1][k+1] = max(dt[i][j+1][k+1], dt[i][j][k]);
					} else { // exceeds!
						dt[i+1][0][k+1] = max(dt[i+1][0][k+1], dt[i][j][k]);
					}
					// use attack!
					for(int l = 0; l <= k && (l-1)*p + j*q < h[i]; l++) {
						if (l*p+j*q >= h[i]) {
							dt[i+1][0][k-l] = max(dt[i+1][0][k-l], dt[i][j][k] + g[i]);
						}
					}
				}
			}
		}
		ans = max(ans, *max_element(dt[n][0], dt[n][0] + 1001));
		ans = max(ans, *max_element(dt[n][1], dt[n][1] + 1001));
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}
