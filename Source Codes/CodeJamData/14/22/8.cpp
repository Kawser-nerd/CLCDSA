#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int ans, Tn, Ti, n, m, k, i, j, a[50], b[50], c[50], fa, fb, fc, pa, pb, pc, la, lb, lc;
long long dp[50][2][2][2];

void upd (long long & a, long long b) {
	a = (a + b);
}

int main () {
	freopen("input.txt", "r", stdin);
	scanf("%d", &Tn);
	for(Ti = 1; Ti <= Tn; Ti++) {
		scanf("%d %d %d", &n, &m, &k);
		
		for(i = 30; i >= 0; i--) {
			a[31 - i] = (n & (1 << i)) > 0;
			b[31 - i] = (m & (1 << i)) > 0;
			c[31 - i] = (k & (1 << i)) > 0;
		}
		
		memset(dp, 0, sizeof(dp));		
		dp[0][1][1][1] = 1;
		for(i = 0; i < 31; i++) 
			for(fa = 0; fa < 2; fa++) for(fb = 0; fb < 2; fb++) for(fc = 0; fc < 2; fc++) if (dp[i][fa][fb][fc]){
				if (fa == 0) la = 1; else la = a[i + 1];
				if (fb == 0) lb = 1; else lb = b[i + 1];
				if (fc == 0) lc = 1; else lc = c[i + 1];
				for(pa = 0; pa <= la; pa++) for(pb = 0; pb <= lb; pb++) {
					pc = pa & pb;
					if (pc > lc) continue;
					upd(dp[i + 1][fa & (pa == la)][fb & (pb == lb)][fc & (pc == lc)], dp[i][fa][fb][fc]);
				}
			}
		printf("Case #%d: %lld\n", Ti, dp[31][0][0][0]);
	}
	return 0;
}