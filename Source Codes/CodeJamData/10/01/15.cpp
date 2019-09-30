#include <stdio.h>


int n, k;
int main() {
	int t;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 1; tt <= t; ++tt) {
		scanf("%d %d", &n, &k);
		while(n) {
			if((k & 1) == 0) {
				k = -1;
				break;
			}
			k >>= 1;
			--n;
		}
		if(k >= 0) printf("Case #%d: ON\n", tt);
		else printf("Case #%d: OFF\n", tt);
	}
	return 0;
}
