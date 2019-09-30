#include <stdio.h>
int calc();

int main(void) {
	//input n declaration
	int n, a, b, k, i, j, cnt, f = 0, p[100] = {}, q[100] = {};
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &k);
	k += 2;
	p[0] = a;
	p[1] = b;
	for (i = 2; i < k; i++) scanf("%d", &p[i]);
	for (i = 0; i < k; i++) q[i] = p[i];

	//calc n printf
	for (i = 0; i < k; i++) {
		cnt = 0;
		for (j = 0; j < k + 2; j++) {
			if (p[i] == q[j]) cnt++;
		}
		if(cnt > 1) f++;
	}

	f == 0 ? printf("YES\n") : printf("NO\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &a, &b);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &k);
  ^
./Main.c:13:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 2; i < k; i++) scanf("%d", &p[i]);
                          ^