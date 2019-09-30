#include <stdio.h>
#define MAXN 60
int main(void) {
	int n, p, s = 0;
	scanf("%d%d", &n, &p);
	long long ans = 1LL << n;
	for(int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		s += v & 1;
	}
	printf("%lld\n", s ? ans >> 1 : p ? 0 : ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &p);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &v);
   ^