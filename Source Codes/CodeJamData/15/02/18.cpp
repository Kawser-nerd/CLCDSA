#include <cstdio>
#include <algorithm>

using namespace std;

int dat[2000];

int main() {
	int T;
	scanf("%d",&T);
	for (int testcase = 1; testcase <= T; testcase++) {
		int ans = INT_MAX;
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; i++) {
			scanf("%d",&dat[i]);
		}
		int maxp = *max_element(dat, dat+n);
		for (int maxv = 1; maxv <= maxp; maxv++) {
			int stage1 = 0;
			for (int i = 0; i < n; i++) stage1 += (dat[i] - 1) / maxv;
			ans = min(ans, stage1 + maxv);
		}
		printf("Case #%d: %d\n", testcase, ans);
	}
}