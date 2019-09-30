#include <stdio.h>

__int64 r[2000], sum[2000];
int to[2000];

int ren, k, n;

int main() {
	int t;
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 1; tt <= t; ++tt) {
		scanf("%d %d %d", &ren, &k, &n);
		for(int i = 0; i < n; ++i) {
			scanf("%I64d", r + i);
		}
		for(int i = 0; i < n; ++i) {
			sum[i] = 0;
			int j = i;
			while(sum[i] + r[j] <= k) {
				sum[i] += r[j++];
				if(j >= n) j = 0;
				if(j == i) break;
			}
			to[i] = j;
		}
		__int64 ans = 0;
		int i = 0;
		while(ren--) {
			ans += sum[i];
			i = to[i];
		}
		printf("Case #%d: %I64d\n", tt, ans);
		
	}
	return 0;
}
