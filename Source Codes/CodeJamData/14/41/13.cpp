#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int n,x;
int s[10003];
int cnts[703];

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		scanf("%d%d",&n,&x);
		memset(cnts,0,sizeof(cnts));
		for(int i = 0; i < n;i++) {
			scanf("%d",&s[i]);
			cnts[s[i]]++;
		}
		int ans = 0;
		for(int i = x; i >= 0; i--) {
			if (cnts[i] == 0) continue;
			if (i+i <= x) {
				int torem = cnts[i] / 2;
				cnts[i] -= torem*2;
				ans += torem;
			}
			for(int j = i-1; j >= 0; j--) {
				if (i+j <= x) {
					int torem = min(cnts[i], cnts[j]);
					cnts[i] -= torem;
					cnts[j] -= torem;
					ans += torem;
				}
			}
			ans += cnts[i];
			cnts[i] = 0;
		}
		printf("Case #%d: %d\n", testcase,ans);
	}
	return 0;
}
