#include <stdio.h>
#include <string.h>

int calc(int from, int to, int m[]) {
	int i, middle = (from + to) / 2;
	
	if (to-from == 1) {
		return m[from] > 0;
	}
	
	for (i=from; i < to; i++) {
		if (m[i] > 0) {
			goto YES;
		}
	}
	
	return 0;
	
	YES:
	for (i=from; i < to; i++) {
		m[i]--;
	}
	
	return 1 + calc(from,middle,m)+ calc(middle,to,m);
}

int main() {
	int t, caso = 1;
	int p, n, m[1050], i, j, ans;
	
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&p);
		
		n = 1 << p;
		
		for (i=0; i < n; i++) {
			scanf("%d\n",&m[i]);
			m[i] = p - m[i];
		}
		for (i=0; i < p; i++) {
			for (j=0; j < (1 << (p-i-1)); j++) {
				scanf("%d",&ans);
			}
		}
		
		ans = calc(0,n,m);
		
		printf("Case #%d: %d\n",caso++,ans);
	}
	
	return 0;
}
